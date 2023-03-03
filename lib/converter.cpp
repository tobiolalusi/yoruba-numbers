#include "converter.hh"
#include "factor20.hh"
#include "factor200.hh"
#include "lookuptable.hh"

std::string converter::to_text(uint32_t input) {
  if (input <= 2000) return Factor200{input};
  return "Only numbers up to 2000 are currently supported.";
}
