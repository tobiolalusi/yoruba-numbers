#ifndef FACTOR200_HH
#define FACTOR200_HH

#include <string>
#include <unordered_map>

#include "factor.hh"

class Factor200 : Factor {
  using Factor::Factor;

  public:
  static std::unordered_map<uint32_t, std::string> specials;
  static std::array<std::string, 6> basic_lhs;
  operator std::string() const override;
  std::string operator+(const std::string&) const override { return ""; }
  std::string operator+() const override { return ""; }

  private:
  [[nodiscard]] std::string ten() const override;
  [[nodiscard]] std::string concat_base(bool next) const override;
};

#endif // FACTOR200_HH
