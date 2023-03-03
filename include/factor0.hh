#ifndef FACTOR0_HH
#define FACTOR0_HH

#include <array>
#include <string>
#include <unordered_map>

#include "factor.hh"

class Factor0 : Factor {
  public:
  using Factor::Factor;
  static std::array<std::string, 10> basic;
  static std::array<std::string, 6> basic_lhs;
  operator std::string() const override;
  std::string operator+(const std::string& rhs) const override;
  std::string operator+() const override;

  private:
  [[nodiscard]] std::string ten() const override { return ""; }
  [[nodiscard]] std::string concat_base(bool) const override { return ""; }
};

#endif // FACTOR0_HH
