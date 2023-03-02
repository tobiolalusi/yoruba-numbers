#include "unit.hh"
#include "lookuptable.hh"

// {0, 1, ..., 9}
std::array<std::string, 10> Unit::basic = {
  "odo",      "oókan", "eéjì", "ẹẹ́ta", "ẹẹ́rin",
  "aárùn-ún", "ẹẹ́fà",  "eéje", "ẹẹ́jọ", "ẹẹ́sàn-án",
};

// {1, 2, 3, 4, 5} for concatenation
std::array<std::string, 6> Unit::basic_lhs{
  "", "oókàn", "eéjì", "ẹẹ́tà", "ẹẹ́rìn", "aárùn",
};

Unit::operator std::string() const { return basic.at(input); }

std::string Unit::operator+(const std::string& rhs) const {
  return basic_lhs.at(input) + rhs;
}

std::string Unit::operator-(const std::string& rhs) const {
  return basic_lhs.at(10 - input) + rhs;
}
