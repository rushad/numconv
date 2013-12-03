#include "numconv.h"
#include "gtest/gtest.h"

#include <ostream>
#include <climits>

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
/*
    TEST_F(ConvTest, ZeroEN10)
    {
      NumericConverter conv(LANG_ENGLISH);
      EXPECT_EQ(std::string("zero"), conv.ToString(0));
    }

    TEST_F(ConvTest, OnesEN10)
    {
      NumericConverter conv(LANG_ENGLISH);
      EXPECT_EQ("one", conv.ToString(1));
      EXPECT_EQ("two", conv.ToString(2));
      EXPECT_EQ("three", conv.ToString(3));
      EXPECT_EQ("four", conv.ToString(4));
      EXPECT_EQ("five", conv.ToString(5));
      EXPECT_EQ("six", conv.ToString(6));
      EXPECT_EQ("seven", conv.ToString(7));
      EXPECT_EQ("eight", conv.ToString(8));
      EXPECT_EQ("nine", conv.ToString(9));
    }

    TEST_F(ConvTest, TeensEN10)
    {
      NumericConverter conv(LANG_ENGLISH);
      EXPECT_EQ("ten", conv.ToString(10));
      EXPECT_EQ("eleven", conv.ToString(11));
      EXPECT_EQ("twelve", conv.ToString(12));
      EXPECT_EQ("thirteen", conv.ToString(13));
      EXPECT_EQ("fourteen", conv.ToString(14));
      EXPECT_EQ("fifteen", conv.ToString(15));
      EXPECT_EQ("sixteen", conv.ToString(16));
      EXPECT_EQ("seventeen", conv.ToString(17));
      EXPECT_EQ("eighteen", conv.ToString(18));
      EXPECT_EQ("nineteen", conv.ToString(19));
    }

    TEST_F(ConvTest, TwoDigitEN10)
    {
      NumericConverter conv(LANG_ENGLISH);
      EXPECT_EQ("twenty", conv.ToString(20));
      EXPECT_EQ("thirty-one", conv.ToString(31));
      EXPECT_EQ("fourty-two", conv.ToString(42));
      EXPECT_EQ("fifty-three", conv.ToString(53));
      EXPECT_EQ("sixty-four", conv.ToString(64));
      EXPECT_EQ("seventy-five", conv.ToString(75));
      EXPECT_EQ("eighty-six", conv.ToString(86));
      EXPECT_EQ("ninety-seven", conv.ToString(97));
    }

    TEST_F(ConvTest, ThreeDigitEN10)
    {
      NumericConverter conv(LANG_ENGLISH);
      EXPECT_EQ("one hundred", conv.ToString(100));
      EXPECT_EQ("one hundred and one", conv.ToString(101));
      EXPECT_EQ("two hundred and twelve", conv.ToString(212));
      EXPECT_EQ("three hundred and twenty-three", conv.ToString(323));
      EXPECT_EQ("four hundred and thirty-four", conv.ToString(434));
      EXPECT_EQ("five hundred and fourty-five", conv.ToString(545));
      EXPECT_EQ("six hundred and fifty-six", conv.ToString(656));
      EXPECT_EQ("seven hundred and sixty-seven", conv.ToString(767));
      EXPECT_EQ("eight hundred and seventy-eight", conv.ToString(878));
      EXPECT_EQ("nine hundred and eighty-nine", conv.ToString(989));
    }

    TEST_F(ConvTest, ThousandsEN10)
    {
      NumericConverter conv(LANG_ENGLISH);
      EXPECT_EQ("one thousand", conv.ToString(1000));
      EXPECT_EQ("one thousand and one", conv.ToString(1001));
      EXPECT_EQ("two hundred thousand and one", conv.ToString(200001));
      EXPECT_EQ("three hundred and two thousand and one", conv.ToString(302001));
      EXPECT_EQ("four hundred and thirty-two thousand five hundred and one", conv.ToString(432501));
      EXPECT_EQ("one hundred and twenty-three thousand four hundred and fifty-six", conv.ToString(123456));
      EXPECT_EQ("one hundred thousand", conv.ToString(100000));
      EXPECT_EQ("nine hundred and ninety-nine thousand nine hundred and ninety-nine", conv.ToString(999999));
      EXPECT_EQ("one hundred and thirteen thousand and one", conv.ToString(113001));
    }

    TEST_F(ConvTest, MillionsEN10)
    {
      NumericConverter conv(LANG_ENGLISH);
      EXPECT_EQ("one million", conv.ToString(1000000));
      EXPECT_EQ("one million and one", conv.ToString(1000001));
      EXPECT_EQ("one hundred million", conv.ToString(100 * 1000000));
      EXPECT_EQ("two hundred and ten million", conv.ToString(210000000));
      EXPECT_EQ("three hundred and twenty-one million one hundred and twenty-three", conv.ToString(321000123));
      EXPECT_EQ("one hundred and twenty-three million four hundred and fifty-six thousand seven hundred and eighty-nine", conv.ToString(123456789));
      EXPECT_EQ("one hundred and three million and six thousand and nine", conv.ToString(103006009));
      EXPECT_EQ("twelve million and thirty-four thousand and fifty-six", conv.ToString(12034056));
      EXPECT_EQ("one million one hundred and twenty-three thousand and one", conv.ToString(1123001));
      EXPECT_EQ("one million and twelve", conv.ToString(1000012));
      EXPECT_EQ("one million one hundred", conv.ToString(1000100));
      EXPECT_EQ("one million one hundred and one", conv.ToString(1000101));
    }

    TEST_F(ConvTest, BillionsEN10)
    {
      NumericConverter conv(LANG_ENGLISH);
      EXPECT_EQ("one billion", conv.ToString(1000000000));
      EXPECT_EQ("one billion and one", conv.ToString(1000000001));
      EXPECT_EQ("one billion and twelve", conv.ToString(1000000012));
      EXPECT_EQ("one billion one hundred and one", conv.ToString(1000000101));
      EXPECT_EQ("one billion one hundred and twenty-three thousand and one", conv.ToString(1000123001));
      EXPECT_EQ("one billion one hundred and twenty-three million and one", conv.ToString(1123000001));
      EXPECT_EQ("one billion and twenty-three million and one", conv.ToString(1023000001));
      EXPECT_EQ("one billion and twenty-three thousand and one", conv.ToString(1000023001));
    }

    TEST_F(ConvTest, ZeroRU10)
    {
      NumericConverter conv(LANG_RUSSIAN);
      EXPECT_EQ(std::string("ноль"), conv.ToString(0));
    }

    TEST_F(ConvTest, OnesRU10)
    {
      NumericConverter conv(LANG_RUSSIAN);
      EXPECT_EQ("один", conv.ToString(1));
      EXPECT_EQ("два", conv.ToString(2));
      EXPECT_EQ("три", conv.ToString(3));
      EXPECT_EQ("четыре", conv.ToString(4));
      EXPECT_EQ("пять", conv.ToString(5));
      EXPECT_EQ("шесть", conv.ToString(6));
      EXPECT_EQ("семь", conv.ToString(7));
      EXPECT_EQ("восемь", conv.ToString(8));
      EXPECT_EQ("девять", conv.ToString(9));
    }

    TEST_F(ConvTest, TeensRU10)
    {
      NumericConverter conv(LANG_RUSSIAN);
      EXPECT_EQ("десять", conv.ToString(10));
      EXPECT_EQ("одиннадцать", conv.ToString(11));
      EXPECT_EQ("двенадцать", conv.ToString(12));
      EXPECT_EQ("тринадцать", conv.ToString(13));
      EXPECT_EQ("четырнадцать", conv.ToString(14));
      EXPECT_EQ("пятнадцать", conv.ToString(15));
      EXPECT_EQ("шестнадцать", conv.ToString(16));
      EXPECT_EQ("семнадцать", conv.ToString(17));
      EXPECT_EQ("восемнадцать", conv.ToString(18));
      EXPECT_EQ("девятнадцать", conv.ToString(19));
    }

    TEST_F(ConvTest, TwoDigitRU10)
    {
      NumericConverter conv(LANG_RUSSIAN);
      EXPECT_EQ("двадцать", conv.ToString(20));
      EXPECT_EQ("тридцать один", conv.ToString(31));
      EXPECT_EQ("сорок два", conv.ToString(42));
      EXPECT_EQ("пятьдесят три", conv.ToString(53));
      EXPECT_EQ("шестьдесят четыре", conv.ToString(64));
      EXPECT_EQ("семьдесят пять", conv.ToString(75));
      EXPECT_EQ("восемьдесят шесть", conv.ToString(86));
      EXPECT_EQ("девяносто семь", conv.ToString(97));
    }

    TEST_F(ConvTest, ThreeDigitRU10)
    {
      NumericConverter conv(LANG_RUSSIAN);
      EXPECT_EQ("сто", conv.ToString(100));
      EXPECT_EQ("сто один", conv.ToString(101));
      EXPECT_EQ("двести двенадцать", conv.ToString(212));
      EXPECT_EQ("триста двадцать три", conv.ToString(323));
      EXPECT_EQ("четыреста тридцать четыре", conv.ToString(434));
      EXPECT_EQ("пятьсот сорок пять", conv.ToString(545));
      EXPECT_EQ("шестьсот пятьдесят шесть", conv.ToString(656));
      EXPECT_EQ("семьсот шестьдесят семь", conv.ToString(767));
      EXPECT_EQ("восемьсот семьдесят восемь", conv.ToString(878));
      EXPECT_EQ("девятьсот восемьдесят девять", conv.ToString(989));
    }

    TEST_F(ConvTest, ThousandsRU10)
    {
      NumericConverter conv(LANG_RUSSIAN);
      EXPECT_EQ("одна тысяча", conv.ToString(1000));
      EXPECT_EQ("одна тысяча один", conv.ToString(1001));
      EXPECT_EQ("двести тысяч один", conv.ToString(200001));
      EXPECT_EQ("триста две тысячи один", conv.ToString(302001));
      EXPECT_EQ("четыреста тридцать две тысячи пятьсот один", conv.ToString(432501));
      EXPECT_EQ("сто двадцать три тысячи четыреста пятьдесят шесть", conv.ToString(123456));
      EXPECT_EQ("сто тысяч", conv.ToString(100000));
      EXPECT_EQ("девятьсот девяносто девять тысяч девятьсот девяносто девять", conv.ToString(999999));
      EXPECT_EQ("сто тринадцать тысяч один", conv.ToString(113001));
    }

    TEST_F(ConvTest, MillionsRU10)
    {
      NumericConverter conv(LANG_RUSSIAN);
      EXPECT_EQ("один миллион", conv.ToString(1000000));
      EXPECT_EQ("один миллион один", conv.ToString(1000001));
      EXPECT_EQ("сто миллионов", conv.ToString(100 * 1000000));
      EXPECT_EQ("двести десять миллионов", conv.ToString(210000000));
      EXPECT_EQ("триста двадцать один миллион сто двадцать три", conv.ToString(321000123));
      EXPECT_EQ("сто двадцать три миллиона четыреста пятьдесят шесть тысяч семьсот восемьдесят девять", conv.ToString(123456789));
      EXPECT_EQ("сто три миллиона шесть тысяч девять", conv.ToString(103006009));
      EXPECT_EQ("двенадцать миллионов тридцать четыре тысячи пятьдесят шесть", conv.ToString(12034056));
      EXPECT_EQ("один миллион сто двадцать три тысячи один", conv.ToString(1123001));
      EXPECT_EQ("один миллион двенадцать", conv.ToString(1000012));
      EXPECT_EQ("один миллион сто", conv.ToString(1000100));
      EXPECT_EQ("один миллион сто один", conv.ToString(1000101));
    }

    TEST_F(ConvTest, BillionsRU10)
    {
      NumericConverter conv(LANG_RUSSIAN);
      EXPECT_EQ("один миллиард", conv.ToString(1000000000));
      EXPECT_EQ("один миллиард один", conv.ToString(1000000001));
      EXPECT_EQ("один миллиард двенадцать", conv.ToString(1000000012));
      EXPECT_EQ("один миллиард сто один", conv.ToString(1000000101));
      EXPECT_EQ("один миллиард сто двадцать три тысячи один", conv.ToString(1000123001));
      EXPECT_EQ("один миллиард сто двадцать три миллиона один", conv.ToString(1123000001));
      EXPECT_EQ("один миллиард двадцать три миллиона один", conv.ToString(1023000001));
      EXPECT_EQ("один миллиард двадцать три тысячи один", conv.ToString(1000023001));
    }

    TEST_F(ConvTest, ThreeDigitEN8)
    {
      NumericConverter conv(LANG_ENGLISH, BASE_OCTAL);
      EXPECT_EQ("one hundred", conv.ToString(0100));
      EXPECT_EQ("one hundred and one", conv.ToString(0101));
      EXPECT_EQ("two hundred and twelve", conv.ToString(0212));
      EXPECT_EQ("three hundred and twenty-three", conv.ToString(0323));
      EXPECT_EQ("four hundred and thirty-four", conv.ToString(0434));
      EXPECT_EQ("five hundred and fourty-five", conv.ToString(0545));
      EXPECT_EQ("six hundred and fifty-six", conv.ToString(0656));
      EXPECT_EQ("seven hundred and sixty-seven", conv.ToString(0767));
    }
*/
  }
}