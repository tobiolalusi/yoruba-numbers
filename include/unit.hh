#ifndef UNIT_HH
#define UNIT_HH

#include <array>
#include <string>

#include "factor20.hh"

class Unit {
  public:
  static std::array<std::string, 10> basic;
  static std::array<std::string, 6> basic_lhs;

  Unit(uint32_t input) : input(input){};

  operator std::string() const;

  std::string operator+(const std::string& rhs) const;
  std::string operator-(const std::string& rhs) const;

  private:
  uint32_t input{};
};

#endif
