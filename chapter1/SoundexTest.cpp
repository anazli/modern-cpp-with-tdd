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
  ASSERT_EQ("A200", soundex.encode("Ax"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
  ASSERT_EQ("A000", soundex.encode("A#"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
  ASSERT_EQ("A234", soundex.encode("Acdl"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
  ASSERT_EQ(4u, soundex.encode("Dcdlb").length());
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters) {
  ASSERT_EQ("B234", soundex.encode("Baeiouhycdl"));
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings) {
  ASSERT_EQ(soundex.encodedDigit('b'), soundex.encodedDigit('f'));
  ASSERT_EQ(soundex.encodedDigit('c'), soundex.encodedDigit('g'));
  ASSERT_EQ(soundex.encodedDigit('d'), soundex.encodedDigit('t'));

  ASSERT_EQ("A123", soundex.encode("Abfcgdt"));
}
