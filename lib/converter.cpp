#include "converter.hh"
#include "factor20.hh"
#include "factor200.hh"
#include "lookuptable.hh"
#include "unit.hh"

std::string converter::to_text(uint32_t input) {
  if (input < 10) return Unit{input};
  if (input < 200) return Factor20{input};
  if (input < 1995) return Factor200{input};
  return "Only numbers up to 1994 are currently supported.";
}
