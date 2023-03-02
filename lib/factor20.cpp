#include "factor20.hh"
#include "lookuptable.hh"
#include "unit.hh"

Factor20::operator std::string() const {
  auto unit_idx = input % 10;
  if (unit_idx == 0) return ten();
  if (unit_idx < 5) return Unit{unit_idx} + concat_base();
  return Unit{unit_idx} - concat_base(true);
}

std::string Factor20::concat_base(bool next) const {
  auto factor10 = input / 10;
  if (next) factor10++;
  if (factor10 == 2) return "ógún";
  if (factor10 == 3) return "ọ́gbọ̀n";
  if (factor10 % 2 == 0) {
    // considers 40 and 140 special pronunciation
    auto prefix = factor10 == 4 || factor10 == 14 ? "ógó" : "ọ́gọ́";
    return prefix + lookuptable::basic_ten_rhs.at(factor10 / 2);
  }
  // considers 130 special pronunciation
  auto prefix = factor10 == 13 ? "áàdó" : "áàdọ́";
  return prefix + lookuptable::basic_ten_rhs.at(factor10 / 2 + 1);
}

std::string Factor20::ten() const {
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
