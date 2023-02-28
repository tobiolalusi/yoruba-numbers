#include "converter.hh"
#include "lookuptable.hh"

namespace {
  // reads the tens of 200 i.e. {40, 50, 60, 70, ..., 190}
  // {10, 20, 30} are already special
  std::string factor20_ten(uint32_t input) {
    auto factor = input / 20;
    auto rest = input % 20;
    std::string prefix{};
    if (rest < 10) {
      // considers 40 and 140 special pronunciation
      prefix = factor == 2 || factor == 7 ? "ogó" : "ọgọ́";
      return prefix + lookuptable::basic_ten_rhs.at(factor);
    }
    // considers 130 special pronunciation
    prefix = factor == 6 ? "àádó" : "àádọ́";
    return prefix + lookuptable::basic_ten_rhs.at(factor + 1);
  }

  std::string factor20_ten_concat_base(uint32_t input) {
    auto index = input / 10;
    auto is_upperbound = input % 10 < 5;
    if (!is_upperbound) index++; // bottom is based on next ten
    std::string prefix = is_upperbound ? "lel" : "dínl";
    if (index == 2) return prefix + "ógún";
    if (index == 3) return prefix + "ọ́gbọ̀n";
    if (index % 2 == 0) {
      // considers 40 and 140 special pronunciation
      prefix += index == 4 || index == 14 ? "ógó" : "ọ́gọ́";
      return prefix + lookuptable::basic_ten_rhs.at(index / 2);
    }
    // considers 130 special pronunciation
    prefix += index == 13 ? "áàdó" : "áàdọ́";
    return prefix + lookuptable::basic_ten_rhs.at(index / 2 + 1);
  }

  std::string factor20_concat(uint32_t input) {
    auto unit_pos = input % 10;
    auto unit_index = unit_pos < 5 ? unit_pos : 10 - unit_pos;
    return lookuptable::basic_lhs.at(unit_index) +
           factor20_ten_concat_base(input);
  }

  std::string factor20(uint32_t input) {
    if (input % 10 == 0) return factor20_ten(input);
    return factor20_concat(input);
  }

} // namespace

std::string converter::to_text(uint32_t input) {
  if (lookuptable::specials.contains(input))
    return lookuptable::specials.at(input);
  if (input < 10) return lookuptable::basic.at(input);
  if (input < 195) return factor20(input);
  return "Only numbers up to 194 are currently supported.";
}
