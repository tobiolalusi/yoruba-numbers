#include "factor200.hh"
#include "factor20.hh"
#include "lookuptable.hh"

std::unordered_map<uint32_t, std::string> Factor200::specials{
  {200, "igba"},
  {300, "ọ̀ọ́dúnrún"},
  {400, "irinwó"},
  {2000, "ẹgbàá"},
};

Factor200::operator std::string() const {
  if (specials.contains(input)) return specials.at(input);
  auto unit20 = input % 100;
  if (unit20 == 0) return ten();
  if (unit20 % 10 < 5) return Factor20{unit20} + concat_base();
  return Factor20{unit20} - concat_base(true);
}

std::string Factor200::concat_base(bool next) const {
  auto factor100 = input / 100;
  std::string prefix{};
  if (next) {
    factor100++;
    prefix = "dίn";
  }
  if (factor100 == 2) return prefix + "léerúgba";
  if (factor100 == 3) return prefix + "lọ́ọ̀dúnrún";
  if (factor100 == 4) return prefix + "léerinwó";
  if (factor100 % 2 == 0) {
    prefix += factor100 == 14 ? "légbé" : "lẹ́gbẹ̀";
    return prefix + lookuptable::basic_ten_rhs.at(factor100 / 2);
  }
  prefix += factor100 == 13 ? "lẹ́ẹ̀dẹ́gbé" : "lẹ́ẹ̀dẹ́gbẹ̀";
  return prefix + lookuptable::basic_ten_rhs.at(factor100 / 2 + 1);
}

std::string Factor200::ten() const {
  auto factor = input / 200;
  auto rest = input % 200;
  if (rest < 100) {
    // considers 140 special pronunciation
    auto prefix = factor == 7 ? "egbè" : "ẹgbẹ̀";
    return prefix + lookuptable::basic_ten_rhs.at(factor);
  }
  // considers 130 special pronunciation
  auto prefix = factor == 6 ? "ẹ̀ẹ́dẹ́gbè" : "ẹ̀ẹ́dẹ́gbẹ̀";
  return prefix + lookuptable::basic_ten_rhs.at(factor + 1);
}
