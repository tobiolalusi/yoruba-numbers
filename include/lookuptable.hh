#ifndef WORDMAP_HH
#define WORDMAP_HH

#include <array>
#include <unordered_map>

namespace lookuptable {

  static std::unordered_map<uint32_t, std::string> specials{
    {11, "oókànlá"}, {12, "eéjìlá"},  {13, "ẹẹ́tàlá"},
    {14, "ẹẹ́rìnlá"}, {15, "ẹ̀ẹ́dógún"}, {25, "ẹ̀ẹ́dọ́gbọ̀n"},
  };

  // the first element is for the number itself
  // the second element is for when the number is concatenated with a tens
  static std::array<std::pair<std::string, std::string>, 10> basic{
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

  static std::array<std::pair<std::string, std::string>, 20> tens{
    std::pair{"odo", ""},               // 0
    std::pair{"ẹẹ́wàá", ""},             // 10
    std::pair{"ogún", "ógún"},          // 20
    std::pair{"ọgbọ̀n", "ọ́gbọ̀n"},        // 30
    std::pair{"ogójì", "ógójì"},        // 40
    std::pair{"àádọ́ta", "áàdọ́ta"},      // 50
    std::pair{"ọgọ́ta", "ọ́gọ́ta"},        // 60
    std::pair{"àádọ́rin", "áàdọ́rin"},    // 70
    std::pair{"ọgọ́rin", "ọ́gọ́rin"},      // 80
    std::pair{"àádọ́rùn-ún", "áàdọ́rùn"}, // 90
    std::pair{"ọgọ́rùn-ún", "ọ́gọ́rùn"},   // 100
  };

} // namespace lookuptable

#endif // WORDMAP_HH
