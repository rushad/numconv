#include "numeric_english.h"

#include "gtest/gtest.h"

namespace Converter
{
  namespace Test
  {
    class TestNumericEnglish : public ::testing::Test
    {
    protected:
      TestNumericEnglish()
        : pConv10(CreateNumericEnglish(BASE_DECIMAL))
        , pConv8(CreateNumericEnglish(BASE_OCTAL))
      {
      }

    protected:
      NumericPtr pConv10;
      NumericPtr pConv8;
    };

    TEST_F(TestNumericEnglish, Zero10)
    {
      EXPECT_EQ(std::string("zero"), pConv10->ToString(0));
    }

    TEST_F(TestNumericEnglish, Ones10)
    {
      EXPECT_EQ("one", pConv10->ToString(1));
      EXPECT_EQ("two", pConv10->ToString(2));
      EXPECT_EQ("three", pConv10->ToString(3));
      EXPECT_EQ("four", pConv10->ToString(4));
      EXPECT_EQ("five", pConv10->ToString(5));
      EXPECT_EQ("six", pConv10->ToString(6));
      EXPECT_EQ("seven", pConv10->ToString(7));
      EXPECT_EQ("eight", pConv10->ToString(8));
      EXPECT_EQ("nine", pConv10->ToString(9));
    }

    TEST_F(TestNumericEnglish, Teens10)
    {
      EXPECT_EQ("ten", pConv10->ToString(10));
      EXPECT_EQ("eleven", pConv10->ToString(11));
      EXPECT_EQ("twelve", pConv10->ToString(12));
      EXPECT_EQ("thirteen", pConv10->ToString(13));
      EXPECT_EQ("fourteen", pConv10->ToString(14));
      EXPECT_EQ("fifteen", pConv10->ToString(15));
      EXPECT_EQ("sixteen", pConv10->ToString(16));
      EXPECT_EQ("seventeen", pConv10->ToString(17));
      EXPECT_EQ("eighteen", pConv10->ToString(18));
      EXPECT_EQ("nineteen", pConv10->ToString(19));
    }

    TEST_F(TestNumericEnglish, TwoDigit10)
    {
      EXPECT_EQ("twenty", pConv10->ToString(20));
      EXPECT_EQ("thirty-one", pConv10->ToString(31));
      EXPECT_EQ("fourty-two", pConv10->ToString(42));
      EXPECT_EQ("fifty-three", pConv10->ToString(53));
      EXPECT_EQ("sixty-four", pConv10->ToString(64));
      EXPECT_EQ("seventy-five", pConv10->ToString(75));
      EXPECT_EQ("eighty-six", pConv10->ToString(86));
      EXPECT_EQ("ninety-seven", pConv10->ToString(97));
    }

    TEST_F(TestNumericEnglish, ThreeDigit10)
    {
      EXPECT_EQ("one hundred", pConv10->ToString(100));
      EXPECT_EQ("one hundred and one", pConv10->ToString(101));
      EXPECT_EQ("two hundred and twelve", pConv10->ToString(212));
      EXPECT_EQ("three hundred and twenty-three", pConv10->ToString(323));
      EXPECT_EQ("four hundred and thirty-four", pConv10->ToString(434));
      EXPECT_EQ("five hundred and fourty-five", pConv10->ToString(545));
      EXPECT_EQ("six hundred and fifty-six", pConv10->ToString(656));
      EXPECT_EQ("seven hundred and sixty-seven", pConv10->ToString(767));
      EXPECT_EQ("eight hundred and seventy-eight", pConv10->ToString(878));
      EXPECT_EQ("nine hundred and eighty-nine", pConv10->ToString(989));
    }

    TEST_F(TestNumericEnglish, Thousands10)
    {
      EXPECT_EQ("one thousand", pConv10->ToString(1000));
      EXPECT_EQ("one thousand and one", pConv10->ToString(1001));
      EXPECT_EQ("two hundred thousand and one", pConv10->ToString(200001));
      EXPECT_EQ("three hundred and two thousand and one", pConv10->ToString(302001));
      EXPECT_EQ("four hundred and thirty-two thousand five hundred and one", pConv10->ToString(432501));
      EXPECT_EQ("one hundred and twenty-three thousand four hundred and fifty-six", pConv10->ToString(123456));
      EXPECT_EQ("one hundred thousand", pConv10->ToString(100000));
      EXPECT_EQ("nine hundred and ninety-nine thousand nine hundred and ninety-nine", pConv10->ToString(999999));
      EXPECT_EQ("one hundred and thirteen thousand and one", pConv10->ToString(113001));
    }

    TEST_F(TestNumericEnglish, Millions10)
    {
      EXPECT_EQ("one million", pConv10->ToString(1000000));
      EXPECT_EQ("one million and one", pConv10->ToString(1000001));
      EXPECT_EQ("one hundred million", pConv10->ToString(100 * 1000000));
      EXPECT_EQ("two hundred and ten million", pConv10->ToString(210000000));
      EXPECT_EQ("three hundred and twenty-one million one hundred and twenty-three", pConv10->ToString(321000123));
      EXPECT_EQ("one hundred and twenty-three million four hundred and fifty-six thousand seven hundred and eighty-nine", pConv10->ToString(123456789));
      EXPECT_EQ("one hundred and three million and six thousand and nine", pConv10->ToString(103006009));
      EXPECT_EQ("twelve million and thirty-four thousand and fifty-six", pConv10->ToString(12034056));
      EXPECT_EQ("one million one hundred and twenty-three thousand and one", pConv10->ToString(1123001));
      EXPECT_EQ("one million and twelve", pConv10->ToString(1000012));
      EXPECT_EQ("one million one hundred", pConv10->ToString(1000100));
      EXPECT_EQ("one million one hundred and one", pConv10->ToString(1000101));
    }

    TEST_F(TestNumericEnglish, Billions10)
    {
      EXPECT_EQ("one billion", pConv10->ToString(1000000000));
      EXPECT_EQ("one billion and one", pConv10->ToString(1000000001));
      EXPECT_EQ("one billion and twelve", pConv10->ToString(1000000012));
      EXPECT_EQ("one billion one hundred and one", pConv10->ToString(1000000101));
      EXPECT_EQ("one billion one hundred and twenty-three thousand and one", pConv10->ToString(1000123001));
      EXPECT_EQ("one billion one hundred and twenty-three million and one", pConv10->ToString(1123000001));
      EXPECT_EQ("one billion and twenty-three million and one", pConv10->ToString(1023000001));
      EXPECT_EQ("one billion and twenty-three thousand and one", pConv10->ToString(1000023001));
    }

    TEST_F(TestNumericEnglish, Zero8)
    {
      EXPECT_EQ(std::string("zero"), pConv8->ToString(00));
    }

    TEST_F(TestNumericEnglish, Ones8)
    {
      EXPECT_EQ("one", pConv8->ToString(01));
      EXPECT_EQ("two", pConv8->ToString(02));
      EXPECT_EQ("three", pConv8->ToString(03));
      EXPECT_EQ("four", pConv8->ToString(04));
      EXPECT_EQ("five", pConv8->ToString(05));
      EXPECT_EQ("six", pConv8->ToString(06));
      EXPECT_EQ("seven", pConv8->ToString(07));
    }

    TEST_F(TestNumericEnglish, Teens8)
    {
      EXPECT_EQ("ten", pConv8->ToString(010));
      EXPECT_EQ("eleven", pConv8->ToString(011));
      EXPECT_EQ("twelve", pConv8->ToString(012));
      EXPECT_EQ("thirteen", pConv8->ToString(013));
      EXPECT_EQ("fourteen", pConv8->ToString(014));
      EXPECT_EQ("fifteen", pConv8->ToString(015));
      EXPECT_EQ("sixteen", pConv8->ToString(016));
      EXPECT_EQ("seventeen", pConv8->ToString(017));
    }

    TEST_F(TestNumericEnglish, TwoDigit8)
    {
      EXPECT_EQ("twenty", pConv8->ToString(020));
      EXPECT_EQ("thirty-one", pConv8->ToString(031));
      EXPECT_EQ("fourty-two", pConv8->ToString(042));
      EXPECT_EQ("fifty-three", pConv8->ToString(053));
      EXPECT_EQ("sixty-four", pConv8->ToString(064));
      EXPECT_EQ("seventy-five", pConv8->ToString(075));
    }

    TEST_F(TestNumericEnglish, ThreeDigit8)
    {
      EXPECT_EQ("one hundred", pConv8->ToString(0100));
      EXPECT_EQ("one hundred and one", pConv8->ToString(0101));
      EXPECT_EQ("two hundred and twelve", pConv8->ToString(0212));
      EXPECT_EQ("three hundred and twenty-three", pConv8->ToString(0323));
      EXPECT_EQ("four hundred and thirty-four", pConv8->ToString(0434));
      EXPECT_EQ("five hundred and fourty-five", pConv8->ToString(0545));
      EXPECT_EQ("six hundred and fifty-six", pConv8->ToString(0656));
      EXPECT_EQ("seven hundred and sixty-seven", pConv8->ToString(0767));
    }

    TEST_F(TestNumericEnglish, Thousands8)
    {
      EXPECT_EQ("one thousand", pConv8->ToString(01000));
      EXPECT_EQ("one thousand and one", pConv8->ToString(01001));
      EXPECT_EQ("two hundred thousand and one", pConv8->ToString(0200001));
      EXPECT_EQ("three hundred and two thousand and one", pConv8->ToString(0302001));
      EXPECT_EQ("four hundred and thirty-two thousand five hundred and one", pConv8->ToString(0432501));
      EXPECT_EQ("one hundred and twenty-three thousand four hundred and fifty-six", pConv8->ToString(0123456));
      EXPECT_EQ("one hundred thousand", pConv8->ToString(0100000));
      EXPECT_EQ("seven hundred and seventy-seven thousand seven hundred and seventy-seven", pConv8->ToString(0777777));
      EXPECT_EQ("one hundred and thirteen thousand and one", pConv8->ToString(0113001));
    }

    TEST_F(TestNumericEnglish, Millions8)
    {
      EXPECT_EQ("one million", pConv8->ToString(01000000));
      EXPECT_EQ("one million and one", pConv8->ToString(01000001));
      EXPECT_EQ("one hundred million", pConv8->ToString(0100 * 01000000));
      EXPECT_EQ("two hundred and ten million", pConv8->ToString(0210000000));
      EXPECT_EQ("three hundred and twenty-one million one hundred and twenty-three", pConv8->ToString(0321000123));
      EXPECT_EQ("one hundred and twenty-three million four hundred and fifty-six thousand seven hundred and sixty-five", pConv8->ToString(0123456765));
      EXPECT_EQ("one hundred and three million and six thousand and seven", pConv8->ToString(0103006007));
      EXPECT_EQ("twelve million and thirty-four thousand and fifty-six", pConv8->ToString(012034056));
      EXPECT_EQ("one million one hundred and twenty-three thousand and one", pConv8->ToString(01123001));
      EXPECT_EQ("one million and twelve", pConv8->ToString(01000012));
      EXPECT_EQ("one million one hundred", pConv8->ToString(01000100));
      EXPECT_EQ("one million one hundred and one", pConv8->ToString(01000101));
    }

    TEST_F(TestNumericEnglish, Billions8)
    {
      EXPECT_EQ("one billion", pConv8->ToString(01000000000));
      EXPECT_EQ("one billion and one", pConv8->ToString(01000000001));
      EXPECT_EQ("one billion and twelve", pConv8->ToString(01000000012));
      EXPECT_EQ("one billion one hundred and one", pConv8->ToString(01000000101));
      EXPECT_EQ("one billion one hundred and twenty-three thousand and one", pConv8->ToString(01000123001));
      EXPECT_EQ("one billion one hundred and twenty-three million and one", pConv8->ToString(01123000001));
      EXPECT_EQ("one billion and twenty-three million and one", pConv8->ToString(01023000001));
      EXPECT_EQ("one billion and twenty-three thousand and one", pConv8->ToString(01000023001));
    }

  }
}