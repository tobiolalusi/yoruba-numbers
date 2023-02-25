#include <fmt/core.h>
#include <iostream>

#include "converter.hh"

int main() {
  fmt::print("-------------------------------\n");
  fmt::print("Number to Yorùbá text converter\n");
  do {
    uint32_t input;
    fmt::print("-------------------------------\n");
    fmt::print("Enter a number: ");
    std::cin >> input;
    auto output = converter::to_text(input);
    fmt::print("{}\n", output);
  } while (true);
}
