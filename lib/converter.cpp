#include "converter.hh"
#include "factor20.hh"
#include "lookuptable.hh"
#include "unit.hh"

std::string converter::to_text(uint32_t input) {
  if (lookuptable::specials.contains(input))
    return lookuptable::specials.at(input);
  if (input < 10) return Unit{input};
  if (input < 195) return Factor20{input};
  return "Only numbers up to 194 are currently supported.";
}
