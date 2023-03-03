#include "factor20.hh"
#include "factor0.hh"
#include "lookuptable.hh"

std::unordered_map<uint32_t, std::string> Factor20::basic{
  {10, "ẹẹ́wàá"},  {11, "ọọ́kànlá"},  {12, "eéjìlá"},
  {13, "ẹẹ́tàlá"}, {14, "ẹẹ́rìnlá"},  {15, "ẹ̀ẹ́dógún"},
  {20, "ogún"},   {25, "ẹ̀ẹ́dọ́gbọ̀n"}, {30, "ọgbọ̀n"},
};

Factor20::operator std::string() const {
  if (input < 10) return Factor0{input};
  if (basic.contains(input)) return basic.at(input);
  auto unit = input % 10;
  if (unit == 0) return ten();
  return Factor0{unit} + concat_base(unit > 4);
}

std::string Factor20::operator+(const std::string& rhs) const {
  return +*this + rhs;
}

std::string Factor20::operator+() const {
  if (input > 99)
    throw std::runtime_error{"[Factor20]: concatenation with lhs > 99"};
  auto index = input < 45 ? input : 100 - input;
  if (index < 10) return +Factor0{index};
  return Factor20{index};
}

std::string Factor20::concat_base(bool next) const {
  auto factor10 = input / 10;
  std::string prefix{};
  if (next) {
    factor10++;
    prefix = "dínl";
  } else prefix = "lel";
  if (factor10 == 2) return prefix + "ógún";
  if (factor10 == 3) return prefix + "ọ́gbọ̀n";
  if (factor10 % 2 == 0) {
    // considers 40 and 140 special pronunciation
    prefix += factor10 == 4 || factor10 == 14 ? "ógó" : "ọ́gọ́";
    return prefix + lookuptable::basic_ten_rhs.at(factor10 / 2);
  }
  // considers 130 special pronunciation
  prefix += factor10 == 13 ? "áàdó" : "áàdọ́";
  return prefix + lookuptable::basic_ten_rhs.at(factor10 / 2 + 1);
}

std::string Factor20::ten() const {
  auto factor = input / 20;
  auto rest = input % 20;
  if (rest < 10) {
    // considers 40 and 140 special pronunciation
    auto prefix = factor == 2 || factor == 7 ? "ogó" : "ọgọ́";
    return prefix + lookuptable::basic_ten_rhs.at(factor);
  }
  // considers 130 special pronunciation
  auto prefix = factor == 6 ? "àádó" : "àádọ́";
  return prefix + lookuptable::basic_ten_rhs.at(factor + 1);
}
