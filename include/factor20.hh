#ifndef FACTOR20_HH
#define FACTOR20_HH

#include "unit.hh"
#include <string>

class Factor20 {
  public:
  Factor20(uint32_t input) : input(input){};

  operator std::string() const;

  [[nodiscard]] std::string concat_base(bool next = false) const;

  private:
  uint32_t input{};

  [[nodiscard]] std::string ten() const;
};

#endif // FACTOR20_HH
