#ifndef FACTOR_HH
#define FACTOR_HH

#include <string>

class Factor {
  public:
  Factor(uint32_t input) : input(input){};

  virtual operator std::string() const = 0;

  // concatenation operator
  virtual std::string operator+(const std::string& rhs) const = 0;

  // forwarded concatenation operator
  virtual std::string operator+() const = 0;

  protected:
  uint32_t input{};
  [[nodiscard]] virtual std::string ten() const = 0;
  [[nodiscard]] virtual std::string concat_base(bool) const = 0;
};

#endif // FACTOR_HH
