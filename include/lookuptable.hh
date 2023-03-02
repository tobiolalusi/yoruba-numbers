#ifndef LOOKUPTABLE_HH
#define LOOKUPTABLE_HH

#include <array>
#include <unordered_map>

namespace lookuptable {

  static std::unordered_map<uint32_t, std::string> specials{
    {10, "ẹẹ́wàá"},   {11, "ọọ́kànlá"}, {12, "eéjìlá"},  {13, "ẹẹ́tàlá"},
    {14, "ẹẹ́rìnlá"}, {15, "ẹ̀ẹ́dógún"}, {20, "ogún"},    {25, "ẹ̀ẹ́dọ́gbọ̀n"},
    {30, "ọgbọ̀n"},   {200, "igba"},   {400, "irinwó"}, {2000, "ẹgbàá"},
  };

  static std::array<std::string, 11> basic_ten_rhs{
    "", "", "jì", "ta", "rin", "rùn-ún", "fà", "je", "jọ", "sàn-án", "wàá",
  };

} // namespace lookuptable

#endif // LOOKUPTABLE_HH
