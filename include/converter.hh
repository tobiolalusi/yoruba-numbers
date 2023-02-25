#ifndef CONVERTER_HH
#define CONVERTER_HH

#include <string>

namespace converter {

  // convert number to text in yoruba
  std::string to_text(uint32_t input);

  // convert text in yoruba to uppercase
  void to_uppercase(const std::string &input);

  // capitalize text in yoruba
  void capitalize(const std::string &input);

}; // namespace converter

#endif // CONVERTER_HH
