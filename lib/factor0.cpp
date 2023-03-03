#include <stdexcept>

#include "factor0.hh"
#include "lookuptable.hh"

std::array<std::string, 10> Factor0::basic{
  "odo",      "oókan", "eéjì", "ẹẹ́ta", "ẹẹ́rin",
  "aárùn-ún", "ẹẹ́fà",  "eéje", "ẹẹ́jọ", "ẹẹ́sàn-án",
};

std::array<std::string, 6> Factor0::basic_lhs{
  "", "oókàn", "eéjì", "ẹẹ́tà", "ẹẹ́rìn", "aárùn",
};

Factor0::operator std::string() const { return basic.at(input); }

std::string Factor0::operator+(const std::string& rhs) const {
  return +*this + rhs;
}

std::string Factor0::operator+() const {
  if (input > 10)
    throw std::runtime_error{"[Factor0]: concatenation with lhs > 10"};
  auto index = input < 5 ? input : 10 - input;
  return basic_lhs.at(index);
}
