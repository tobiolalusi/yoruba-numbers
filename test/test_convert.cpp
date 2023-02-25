#include <doctest/doctest.h>

#include "converter.hh"

TEST_SUITE_BEGIN("text conversion");

TEST_CASE("0 to 10") {
  CHECK_EQ(converter::to_text(0), "odo");
  CHECK_EQ(converter::to_text(1), "oókan");
  CHECK_EQ(converter::to_text(2), "eéjì");
  CHECK_EQ(converter::to_text(3), "ẹẹ́ta");
  CHECK_EQ(converter::to_text(4), "ẹẹ́rin");
  CHECK_EQ(converter::to_text(5), "aárùn-ún");
  CHECK_EQ(converter::to_text(6), "ẹẹ́fà");
  CHECK_EQ(converter::to_text(7), "eéje");
  CHECK_EQ(converter::to_text(8), "ẹẹ́jọ");
  CHECK_EQ(converter::to_text(9), "ẹẹ́sàn-án");
  CHECK_EQ(converter::to_text(10), "ẹẹ́wàá");
}

TEST_CASE("11 to 20") {
  CHECK_EQ(converter::to_text(11), "oókànlá");
  CHECK_EQ(converter::to_text(12), "eéjìlá");
  CHECK_EQ(converter::to_text(13), "ẹẹ́tàlá");
  CHECK_EQ(converter::to_text(14), "ẹẹ́rìnlá");
  CHECK_EQ(converter::to_text(15), "ẹ̀ẹ́dógún");
  CHECK_EQ(converter::to_text(16), "ẹẹ́rìndínlógún");
  CHECK_EQ(converter::to_text(17), "ẹẹ́tàdínlógún");
  CHECK_EQ(converter::to_text(18), "eéjìdínlógún");
  CHECK_EQ(converter::to_text(19), "oókàndínlógún");
  CHECK_EQ(converter::to_text(20), "ogún");
}

TEST_CASE("21 to 30") {
  CHECK_EQ(converter::to_text(21), "oókànlelógún");
  CHECK_EQ(converter::to_text(22), "eéjìlelógún");
  CHECK_EQ(converter::to_text(23), "ẹẹ́tàlelógún");
  CHECK_EQ(converter::to_text(24), "ẹẹ́rìnlelógún");
  CHECK_EQ(converter::to_text(25), "ẹ̀ẹ́dọ́gbọ̀n");
  CHECK_EQ(converter::to_text(26), "ẹẹ́rìndínlọ́gbọ̀n");
  CHECK_EQ(converter::to_text(27), "ẹẹ́tàdínlọ́gbọ̀n");
  CHECK_EQ(converter::to_text(28), "eéjìdínlọ́gbọ̀n");
  CHECK_EQ(converter::to_text(29), "oókàndínlọ́gbọ̀n");
  CHECK_EQ(converter::to_text(30), "ọgbọ̀n");
}

TEST_CASE("10 different numbers under 100") {
  CHECK_EQ(converter::to_text(42), "eéjìlelógójì");
  CHECK_EQ(converter::to_text(69), "oókàndínláàdọ́rin");
  CHECK_EQ(converter::to_text(73), "ẹẹ́tàleláàdọ́rin");
  CHECK_EQ(converter::to_text(87), "ẹẹ́tàdínláàdọ́rùn");
  CHECK_EQ(converter::to_text(91), "oókànleláàdọ́rùn");
  CHECK_EQ(converter::to_text(95), "aárùndínlọ́gọ́rùn");
  CHECK_EQ(converter::to_text(99), "oókàndínlọ́gọ́rùn");
  CHECK_EQ(converter::to_text(55), "aárùndínlọ́gọ́ta");
  CHECK_EQ(converter::to_text(81), "oókànlelọ́gọ́rin");
  CHECK_EQ(converter::to_text(33), "ẹẹ́tàlelọ́gbọ̀n");
}

TEST_SUITE_END();
