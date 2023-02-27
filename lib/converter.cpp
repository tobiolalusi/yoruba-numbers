#include "converter.hh"
#include "lookuptable.hh"

namespace {
  enum concat_mode { more, less, none };

  // reads the tens of 200 i.e. [10, 20, 30, 40, 50, 60, 70, ..., 190]
  std::string ten_none(uint32_t index) {
    if (index == 1) return "ẹẹ́wàá";
    if (index == 2) return "ogún";
    if (index == 3) return "ọgbọ̀n";
    std::string prefix{};
    if (index % 2 == 0) {
      prefix = index == 4 || index == 14 ? "ogó" : "ọgọ́";
      return prefix + lookuptable::basic_ten_suffix.at(index / 2);
    }
    prefix = index == 13 ? "àádó" : "àádọ́";
    return prefix + lookuptable::basic_ten_suffix.at(index / 2 + 1);
  }

  // reads the tens of 200, specifically with more or less concatenation
  std::string ten_concat(uint32_t index, std::string& prefix) {
    if (index == 2) return prefix + "ógún";
    if (index == 3) return prefix + "ọ́gbọ̀n";
    if (index % 2 == 0) {
      prefix += index == 4 || index == 14 ? "ógó" : "ọ́gọ́";
      return prefix + lookuptable::basic_ten_suffix.at(index / 2);
    }
    prefix += index == 13 ? "áàdó" : "áàdọ́";
    return prefix + lookuptable::basic_ten_suffix.at(index / 2 + 1);
  }

  std::string ten(uint32_t index, const concat_mode& mode = none) {
    if (mode == concat_mode::none) return ten_none(index);
    std::string prefix{};
    if (mode == concat_mode::less) {
      ++index;             // bottom is based on the next ten
      prefix = "dínl";     // din-ni-
    } else prefix = "lel"; // le-ni-
    return ten_concat(index, prefix);
  }

  std::string hundred(uint32_t input) {
    auto unit_pos = input % 10;
    if (unit_pos == 0) return ten(input / 10, concat_mode::none);
    auto is_upperbound = unit_pos < 5;
    auto mode = is_upperbound ? concat_mode::more : concat_mode::less;
    auto unit_index = is_upperbound ? unit_pos : 10 - unit_pos;
    return lookuptable::basic.at(unit_index).second + ten(input / 10, mode);
  }

} // namespace

std::string converter::to_text(uint32_t input) {
  if (lookuptable::specials.contains(input))
    return lookuptable::specials.at(input);
  if (input < 10) return lookuptable::basic.at(input).first;
  if (input < 195) return hundred(input);
  return "Only numbers up to 194 are currently supported.";
}
