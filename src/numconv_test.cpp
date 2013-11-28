#include "numconv.h"
#include "gtest/gtest.h"

namespace Converter
{
  namespace Test
  {
    class ConvTest : public ::testing::Test
    {
    protected:
      // You can remove any or all of the following functions if its body
      // is empty.

      ConvTest() {
        // You can do set-up work for each test here.
      }
    };

    TEST_F(ConvTest, Zero)
    {
      UIntToString conv;
      EXPECT_EQ(std::string("zero"), conv(0));
    }

    TEST_F(ConvTest, Ones)
    {
      UIntToString conv;
      EXPECT_EQ("one", conv(1));
      EXPECT_EQ("two", conv(2));
      EXPECT_EQ("three", conv(3));
      EXPECT_EQ("four", conv(4));
      EXPECT_EQ("five", conv(5));
      EXPECT_EQ("six", conv(6));
      EXPECT_EQ("seven", conv(7));
      EXPECT_EQ("eight", conv(8));
      EXPECT_EQ("nine", conv(9));
    }

    TEST_F(ConvTest, Teens)
    {
      UIntToString conv;
      EXPECT_EQ("ten", conv(10));
      EXPECT_EQ("eleven", conv(11));
      EXPECT_EQ("twelve", conv(12));
      EXPECT_EQ("thirteen", conv(13));
      EXPECT_EQ("fourteen", conv(14));
      EXPECT_EQ("fifteen", conv(15));
      EXPECT_EQ("sixteen", conv(16));
      EXPECT_EQ("seventeen", conv(17));
      EXPECT_EQ("eighteen", conv(18));
      EXPECT_EQ("nineteen", conv(19));
    }

    TEST_F(ConvTest, TwoDigit)
    {
      UIntToString conv;
      EXPECT_EQ("twenty", conv(20));
      EXPECT_EQ("thirty-one", conv(31));
      EXPECT_EQ("fourty-two", conv(42));
      EXPECT_EQ("fifty-three", conv(53));
      EXPECT_EQ("sixty-four", conv(64));
      EXPECT_EQ("seventy-five", conv(75));
      EXPECT_EQ("eighty-six", conv(86));
      EXPECT_EQ("ninety-seven", conv(97));
    }

    TEST_F(ConvTest, ThreeDigit)
    {
      UIntToString conv;
      EXPECT_EQ("one hundred", conv(100));
      EXPECT_EQ("one hundred and one", conv(101));
      EXPECT_EQ("two hundred and twelve", conv(212));
      EXPECT_EQ("three hundred and twenty-three", conv(323));
      EXPECT_EQ("four hundred and thirty-four", conv(434));
      EXPECT_EQ("five hundred and fourty-five", conv(545));
      EXPECT_EQ("six hundred and fifty-six", conv(656));
      EXPECT_EQ("seven hundred and sixty-seven", conv(767));
      EXPECT_EQ("eight hundred and seventy-eight", conv(878));
      EXPECT_EQ("nine hundred and eighty-nine", conv(989));
    }

    TEST_F(ConvTest, Thousands)
    {
      UIntToString conv;
      EXPECT_EQ("one thousand", conv(1000));
      EXPECT_EQ("one thousand and one", conv(1001));
      EXPECT_EQ("two hundred thousand and one", conv(200001));
      EXPECT_EQ("three hundred and two thousand and one", conv(302001));
      EXPECT_EQ("four hundred and thirty-two thousand five hundred and one", conv(432501));
      EXPECT_EQ("one hundred and twenty-three thousand four hundred and fifty-six", conv(123456));
      EXPECT_EQ("one hundred thousand", conv(100000));
      EXPECT_EQ("nine hundred and ninety-nine thousand nine hundred and ninety-nine", conv(999999));
      EXPECT_EQ("one hundred and thirteen thousand and one", conv(113001));
    }

    TEST_F(ConvTest, Millions)
    {
      UIntToString conv;
      EXPECT_EQ("one million", conv(1000000));
      EXPECT_EQ("one million and one", conv(1000001));
      EXPECT_EQ("one hundred million", conv(100 * 1000000));
      EXPECT_EQ("two hundred and ten million", conv(210000000));
      EXPECT_EQ("three hundred and twenty-one million one hundred and twenty-three", conv(321000123));
      EXPECT_EQ("one hundred and twenty-three million four hundred and fifty-six thousand seven hundred and eighty-nine", conv(123456789));
      EXPECT_EQ("one hundred and three million and six thousand and nine", conv(103006009));
      EXPECT_EQ("twelve million and thirty-four thousand and fifty-six", conv(12034056));
    }

    TEST_F(ConvTest, ThreeDigitOct)
    {
      UIntToString conv(BASE_OCTAL);
      EXPECT_EQ("one hundred", conv(0100));
      EXPECT_EQ("one hundred and one", conv(0101));
      EXPECT_EQ("two hundred and twelve", conv(0212));
      EXPECT_EQ("three hundred and twenty-three", conv(0323));
      EXPECT_EQ("four hundred and thirty-four", conv(0434));
      EXPECT_EQ("five hundred and fourty-five", conv(0545));
      EXPECT_EQ("six hundred and fifty-six", conv(0656));
      EXPECT_EQ("seven hundred and sixty-seven", conv(0767));
    }

    TEST_F(ConvTest, InvalidNumShouldThrowException)
    {
      UIntToString conv;
      try
      {
        conv(1000000000);
        FAIL();
      }
      catch(const std::exception&)
      {
      }
    }
  }
}