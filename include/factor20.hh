#ifndef FACTOR20_HH
#define FACTOR20_HH

#include <array>
#include <string>
#include <unordered_map>

#include "factor.hh"

class Factor20 : Factor {
  using Factor::Factor;

  public:
  static std::unordered_map<uint32_t, std::string> basic;
  static std::array<std::string, 6> basic_lhs;
  operator std::string() const override;
  std::string operator+(const std::string& rhs) const override;
  std::string operator+() const override;

  private:
  [[nodiscard]] std::string ten() const override;
  [[nodiscard]] std::string concat_base(bool) const override;
};

#endif // FACTOR20_HH
