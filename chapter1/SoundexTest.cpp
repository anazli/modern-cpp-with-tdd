#include "Soundex.h"
#include "gtest/gtest.h"

class SoundexEncoding : public testing::Test {
 public:
  Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
  auto encoded = soundex.encode("A");

  ASSERT_EQ("A000", encoded);
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
  auto encoded = soundex.encode("I");

  ASSERT_EQ("I000", encoded);
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
  ASSERT_EQ("A100", soundex.encode("Ab"));
}