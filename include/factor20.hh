#ifndef FACTOR20_HH
#define FACTOR20_HH

#include <array>
#include <string>
#include <unordered_map>

class Factor20 {
  public:
  static std::unordered_map<uint32_t, std::string> basic;
  static std::array<std::string, 6> basic_lhs;

  Factor20(uint32_t input) : input(input){};

  operator std::string() const;

  // concatenation operators
  std::string operator+(const std::string& rhs) const;
  std::string operator-(const std::string& rhs) const;

  private:
  uint32_t input{};

  [[nodiscard]] std::string ten() const;
  [[nodiscard]] std::string concat_base(bool next = false) const;
};

#endif // FACTOR20_HH
