#ifndef WORDMAP_HH
#define WORDMAP_HH

#include <array>
#include <unordered_map>

namespace lookuptable {

  std::unordered_map<uint32_t, std::string> specials{
    {11, "ọọ́kànlá"}, {12, "eéjìlá"}, {13, "ẹẹ́tàlá"},   {14, "ẹẹ́rìnlá"},
    {15, "ẹ̀ẹ́dógún"}, {20, "ogún"},   {25, "ẹ̀ẹ́dọ́gbọ̀n"},
  };

  // the first element is for the number itself
  // the second element is for when the number is concatenated with a ten
  std::array<std::pair<std::string, std::string>, 10> basic{
    std::pair{"odo", "odo"},        // 0
    std::pair{"oókan", "oókàn"},    // 1
    std::pair{"eéjì", "eéjì"},      // 2
    std::pair{"ẹẹ́ta", "ẹẹ́tà"},      // 3
    std::pair{"ẹẹ́rin", "ẹẹ́rìn"},    // 4
    std::pair{"aárùn-ún", "aárùn"}, // 5
    std::pair{"ẹẹ́fà", ""},          // 6
    std::pair{"eéje", ""},          // 7
    std::pair{"ẹẹ́jọ", ""},          // 8
    std::pair{"ẹẹ́sàn-án", ""},      // 9
  };

  std::array<std::string, 11> basic_ten_suffix{
    "", "", "jì", "ta", "rin", "rùn-ún", "fà", "je", "jọ", "sàn-án", "wàá",
  };

} // namespace lookuptable

#endif // WORDMAP_HH
