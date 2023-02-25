#include "converter.hh"
#include "lookuptable.hh"

namespace {
  std::string under100(uint32_t input) {
    auto base = input / 10;
    auto pos = input % 10;
    auto is_upperbound = pos < 5;
    auto lhs_index = is_upperbound ? pos : 10 - pos;
    auto rhs_index = is_upperbound ? base : base + 1;
    return lookuptable::basic.at(lhs_index).second +
           (is_upperbound ? "lel" : "dínl") +
           lookuptable::tens.at(rhs_index).second;
  }
} // namespace

std::string converter::to_text(uint32_t input) {
  if (input % 10 == 0) return lookuptable::tens.at(input / 10).first;
  if (lookuptable::specials.contains(input))
    return lookuptable::specials.at(input);
  if (input < 10) return lookuptable::basic.at(input).first;
  if (input < 100) return under100(input);
  return "Only numbers up to 100 are currently supported.";
}
