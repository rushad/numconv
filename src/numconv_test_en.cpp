#include "numconv.h"
#include "gtest/gtest.h"

#include <ostream>
#include <climits>

#define LANG_EN "EN"
#define LANG_RU "RU"

namespace Converter
{
  namespace Test
  {
    class ConvTest : public ::testing::Test
    {
    public:
      ConvTest() 
      {
        Factory.Add(LANG_EN, EnglishNumericConverter::createInstance);
        Factory.Add(LANG_RU, RussianNumericConverter::createInstance);
      }
      NumericConverterFactory* GetFactory() const
      {
        return (NumericConverterFactory*)&Factory;
      }
    private:
      NumericConverterFactory Factory;
    };

    TEST_F(ConvTest, ZeroEN10)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_EN, BASE_DECIMAL));
      EXPECT_EQ(std::string("zero"), convPtr->ToString(0));
    }

    TEST_F(ConvTest, OnesEN10)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_EN, BASE_DECIMAL));
      EXPECT_EQ("one", convPtr->ToString(1));
      EXPECT_EQ("two", convPtr->ToString(2));
      EXPECT_EQ("three", convPtr->ToString(3));
      EXPECT_EQ("four", convPtr->ToString(4));
      EXPECT_EQ("five", convPtr->ToString(5));
      EXPECT_EQ("six", convPtr->ToString(6));
      EXPECT_EQ("seven", convPtr->ToString(7));
      EXPECT_EQ("eight", convPtr->ToString(8));
      EXPECT_EQ("nine", convPtr->ToString(9));
    }

    TEST_F(ConvTest, TeensEN10)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_EN, BASE_DECIMAL));
      EXPECT_EQ("ten", convPtr->ToString(10));
      EXPECT_EQ("eleven", convPtr->ToString(11));
      EXPECT_EQ("twelve", convPtr->ToString(12));
      EXPECT_EQ("thirteen", convPtr->ToString(13));
      EXPECT_EQ("fourteen", convPtr->ToString(14));
      EXPECT_EQ("fifteen", convPtr->ToString(15));
      EXPECT_EQ("sixteen", convPtr->ToString(16));
      EXPECT_EQ("seventeen", convPtr->ToString(17));
      EXPECT_EQ("eighteen", convPtr->ToString(18));
      EXPECT_EQ("nineteen", convPtr->ToString(19));
    }

    TEST_F(ConvTest, TwoDigitEN10)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_EN, BASE_DECIMAL));
      EXPECT_EQ("twenty", convPtr->ToString(20));
      EXPECT_EQ("thirty-one", convPtr->ToString(31));
      EXPECT_EQ("fourty-two", convPtr->ToString(42));
      EXPECT_EQ("fifty-three", convPtr->ToString(53));
      EXPECT_EQ("sixty-four", convPtr->ToString(64));
      EXPECT_EQ("seventy-five", convPtr->ToString(75));
      EXPECT_EQ("eighty-six", convPtr->ToString(86));
      EXPECT_EQ("ninety-seven", convPtr->ToString(97));
    }

    TEST_F(ConvTest, ThreeDigitEN10)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_EN, BASE_DECIMAL));
      EXPECT_EQ("one hundred", convPtr->ToString(100));
      EXPECT_EQ("one hundred and one", convPtr->ToString(101));
      EXPECT_EQ("two hundred and twelve", convPtr->ToString(212));
      EXPECT_EQ("three hundred and twenty-three", convPtr->ToString(323));
      EXPECT_EQ("four hundred and thirty-four", convPtr->ToString(434));
      EXPECT_EQ("five hundred and fourty-five", convPtr->ToString(545));
      EXPECT_EQ("six hundred and fifty-six", convPtr->ToString(656));
      EXPECT_EQ("seven hundred and sixty-seven", convPtr->ToString(767));
      EXPECT_EQ("eight hundred and seventy-eight", convPtr->ToString(878));
      EXPECT_EQ("nine hundred and eighty-nine", convPtr->ToString(989));
    }

    TEST_F(ConvTest, ThousandsEN10)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_EN, BASE_DECIMAL));
      EXPECT_EQ("one thousand", convPtr->ToString(1000));
      EXPECT_EQ("one thousand and one", convPtr->ToString(1001));
      EXPECT_EQ("two hundred thousand and one", convPtr->ToString(200001));
      EXPECT_EQ("three hundred and two thousand and one", convPtr->ToString(302001));
      EXPECT_EQ("four hundred and thirty-two thousand five hundred and one", convPtr->ToString(432501));
      EXPECT_EQ("one hundred and twenty-three thousand four hundred and fifty-six", convPtr->ToString(123456));
      EXPECT_EQ("one hundred thousand", convPtr->ToString(100000));
      EXPECT_EQ("nine hundred and ninety-nine thousand nine hundred and ninety-nine", convPtr->ToString(999999));
      EXPECT_EQ("one hundred and thirteen thousand and one", convPtr->ToString(113001));
    }

    TEST_F(ConvTest, MillionsEN10)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_EN, BASE_DECIMAL));
      EXPECT_EQ("one million", convPtr->ToString(1000000));
      EXPECT_EQ("one million and one", convPtr->ToString(1000001));
      EXPECT_EQ("one hundred million", convPtr->ToString(100 * 1000000));
      EXPECT_EQ("two hundred and ten million", convPtr->ToString(210000000));
      EXPECT_EQ("three hundred and twenty-one million one hundred and twenty-three", convPtr->ToString(321000123));
      EXPECT_EQ("one hundred and twenty-three million four hundred and fifty-six thousand seven hundred and eighty-nine", convPtr->ToString(123456789));
      EXPECT_EQ("one hundred and three million and six thousand and nine", convPtr->ToString(103006009));
      EXPECT_EQ("twelve million and thirty-four thousand and fifty-six", convPtr->ToString(12034056));
      EXPECT_EQ("one million one hundred and twenty-three thousand and one", convPtr->ToString(1123001));
      EXPECT_EQ("one million and twelve", convPtr->ToString(1000012));
      EXPECT_EQ("one million one hundred", convPtr->ToString(1000100));
      EXPECT_EQ("one million one hundred and one", convPtr->ToString(1000101));
    }

    TEST_F(ConvTest, BillionsEN10)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_EN, BASE_DECIMAL));
      EXPECT_EQ("one billion", convPtr->ToString(1000000000));
      EXPECT_EQ("one billion and one", convPtr->ToString(1000000001));
      EXPECT_EQ("one billion and twelve", convPtr->ToString(1000000012));
      EXPECT_EQ("one billion one hundred and one", convPtr->ToString(1000000101));
      EXPECT_EQ("one billion one hundred and twenty-three thousand and one", convPtr->ToString(1000123001));
      EXPECT_EQ("one billion one hundred and twenty-three million and one", convPtr->ToString(1123000001));
      EXPECT_EQ("one billion and twenty-three million and one", convPtr->ToString(1023000001));
      EXPECT_EQ("one billion and twenty-three thousand and one", convPtr->ToString(1000023001));
    }

    TEST_F(ConvTest, ZeroRU10)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_RU, BASE_DECIMAL));
      EXPECT_EQ(std::string("ноль"), convPtr->ToString(0));
    }

    TEST_F(ConvTest, OnesRU10)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_RU, BASE_DECIMAL));
      EXPECT_EQ("один", convPtr->ToString(1));
      EXPECT_EQ("два", convPtr->ToString(2));
      EXPECT_EQ("три", convPtr->ToString(3));
      EXPECT_EQ("четыре", convPtr->ToString(4));
      EXPECT_EQ("пять", convPtr->ToString(5));
      EXPECT_EQ("шесть", convPtr->ToString(6));
      EXPECT_EQ("семь", convPtr->ToString(7));
      EXPECT_EQ("восемь", convPtr->ToString(8));
      EXPECT_EQ("девять", convPtr->ToString(9));
    }

    TEST_F(ConvTest, TeensRU10)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_RU, BASE_DECIMAL));
      EXPECT_EQ("десять", convPtr->ToString(10));
      EXPECT_EQ("одиннадцать", convPtr->ToString(11));
      EXPECT_EQ("двенадцать", convPtr->ToString(12));
      EXPECT_EQ("тринадцать", convPtr->ToString(13));
      EXPECT_EQ("четырнадцать", convPtr->ToString(14));
      EXPECT_EQ("пятнадцать", convPtr->ToString(15));
      EXPECT_EQ("шестнадцать", convPtr->ToString(16));
      EXPECT_EQ("семнадцать", convPtr->ToString(17));
      EXPECT_EQ("восемнадцать", convPtr->ToString(18));
      EXPECT_EQ("девятнадцать", convPtr->ToString(19));
    }

    TEST_F(ConvTest, TwoDigitRU10)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_RU, BASE_DECIMAL));
      EXPECT_EQ("двадцать", convPtr->ToString(20));
      EXPECT_EQ("тридцать один", convPtr->ToString(31));
      EXPECT_EQ("сорок два", convPtr->ToString(42));
      EXPECT_EQ("пятьдесят три", convPtr->ToString(53));
      EXPECT_EQ("шестьдесят четыре", convPtr->ToString(64));
      EXPECT_EQ("семьдесят пять", convPtr->ToString(75));
      EXPECT_EQ("восемьдесят шесть", convPtr->ToString(86));
      EXPECT_EQ("девяносто семь", convPtr->ToString(97));
    }

    TEST_F(ConvTest, ThreeDigitRU10)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_RU, BASE_DECIMAL));
      EXPECT_EQ("сто", convPtr->ToString(100));
      EXPECT_EQ("сто один", convPtr->ToString(101));
      EXPECT_EQ("двести двенадцать", convPtr->ToString(212));
      EXPECT_EQ("триста двадцать три", convPtr->ToString(323));
      EXPECT_EQ("четыреста тридцать четыре", convPtr->ToString(434));
      EXPECT_EQ("пятьсот сорок пять", convPtr->ToString(545));
      EXPECT_EQ("шестьсот пятьдесят шесть", convPtr->ToString(656));
      EXPECT_EQ("семьсот шестьдесят семь", convPtr->ToString(767));
      EXPECT_EQ("восемьсот семьдесят восемь", convPtr->ToString(878));
      EXPECT_EQ("девятьсот восемьдесят девять", convPtr->ToString(989));
    }

    TEST_F(ConvTest, ThousandsRU10)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_RU, BASE_DECIMAL));
      EXPECT_EQ("одна тысяча", convPtr->ToString(1000));
      EXPECT_EQ("одна тысяча один", convPtr->ToString(1001));
      EXPECT_EQ("двести тысяч один", convPtr->ToString(200001));
      EXPECT_EQ("триста две тысячи один", convPtr->ToString(302001));
      EXPECT_EQ("четыреста тридцать две тысячи пятьсот один", convPtr->ToString(432501));
      EXPECT_EQ("сто двадцать три тысячи четыреста пятьдесят шесть", convPtr->ToString(123456));
      EXPECT_EQ("сто тысяч", convPtr->ToString(100000));
      EXPECT_EQ("девятьсот девяносто девять тысяч девятьсот девяносто девять", convPtr->ToString(999999));
      EXPECT_EQ("сто тринадцать тысяч один", convPtr->ToString(113001));
    }

    TEST_F(ConvTest, MillionsRU10)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_RU, BASE_DECIMAL));
      EXPECT_EQ("один миллион", convPtr->ToString(1000000));
      EXPECT_EQ("один миллион один", convPtr->ToString(1000001));
      EXPECT_EQ("сто миллионов", convPtr->ToString(100 * 1000000));
      EXPECT_EQ("двести десять миллионов", convPtr->ToString(210000000));
      EXPECT_EQ("триста двадцать один миллион сто двадцать три", convPtr->ToString(321000123));
      EXPECT_EQ("сто двадцать три миллиона четыреста пятьдесят шесть тысяч семьсот восемьдесят девять", convPtr->ToString(123456789));
      EXPECT_EQ("сто три миллиона шесть тысяч девять", convPtr->ToString(103006009));
      EXPECT_EQ("двенадцать миллионов тридцать четыре тысячи пятьдесят шесть", convPtr->ToString(12034056));
      EXPECT_EQ("один миллион сто двадцать три тысячи один", convPtr->ToString(1123001));
      EXPECT_EQ("один миллион двенадцать", convPtr->ToString(1000012));
      EXPECT_EQ("один миллион сто", convPtr->ToString(1000100));
      EXPECT_EQ("один миллион сто один", convPtr->ToString(1000101));
    }

    TEST_F(ConvTest, BillionsRU10)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_RU, BASE_DECIMAL));
      EXPECT_EQ("один миллиард", convPtr->ToString(1000000000));
      EXPECT_EQ("один миллиард один", convPtr->ToString(1000000001));
      EXPECT_EQ("один миллиард двенадцать", convPtr->ToString(1000000012));
      EXPECT_EQ("один миллиард сто один", convPtr->ToString(1000000101));
      EXPECT_EQ("один миллиард сто двадцать три тысячи один", convPtr->ToString(1000123001));
      EXPECT_EQ("один миллиард сто двадцать три миллиона один", convPtr->ToString(1123000001));
      EXPECT_EQ("один миллиард двадцать три миллиона один", convPtr->ToString(1023000001));
      EXPECT_EQ("один миллиард двадцать три тысячи один", convPtr->ToString(1000023001));
    }

    TEST_F(ConvTest, ZeroEN8)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_EN, BASE_OCTAL));
      EXPECT_EQ(std::string("zero"), convPtr->ToString(00));
    }

    TEST_F(ConvTest, OnesEN8)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_EN, BASE_OCTAL));
      EXPECT_EQ("one", convPtr->ToString(01));
      EXPECT_EQ("two", convPtr->ToString(02));
      EXPECT_EQ("three", convPtr->ToString(03));
      EXPECT_EQ("four", convPtr->ToString(04));
      EXPECT_EQ("five", convPtr->ToString(05));
      EXPECT_EQ("six", convPtr->ToString(06));
      EXPECT_EQ("seven", convPtr->ToString(07));
    }

    TEST_F(ConvTest, TeensEN8)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_EN, BASE_OCTAL));
      EXPECT_EQ("ten", convPtr->ToString(010));
      EXPECT_EQ("eleven", convPtr->ToString(011));
      EXPECT_EQ("twelve", convPtr->ToString(012));
      EXPECT_EQ("thirteen", convPtr->ToString(013));
      EXPECT_EQ("fourteen", convPtr->ToString(014));
      EXPECT_EQ("fifteen", convPtr->ToString(015));
      EXPECT_EQ("sixteen", convPtr->ToString(016));
      EXPECT_EQ("seventeen", convPtr->ToString(017));
    }

    TEST_F(ConvTest, TwoDigitEN8)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_EN, BASE_OCTAL));
      EXPECT_EQ("twenty", convPtr->ToString(020));
      EXPECT_EQ("thirty-one", convPtr->ToString(031));
      EXPECT_EQ("fourty-two", convPtr->ToString(042));
      EXPECT_EQ("fifty-three", convPtr->ToString(053));
      EXPECT_EQ("sixty-four", convPtr->ToString(064));
      EXPECT_EQ("seventy-five", convPtr->ToString(075));
    }

    TEST_F(ConvTest, ThreeDigitEN8)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_EN, BASE_OCTAL));
      EXPECT_EQ("one hundred", convPtr->ToString(0100));
      EXPECT_EQ("one hundred and one", convPtr->ToString(0101));
      EXPECT_EQ("two hundred and twelve", convPtr->ToString(0212));
      EXPECT_EQ("three hundred and twenty-three", convPtr->ToString(0323));
      EXPECT_EQ("four hundred and thirty-four", convPtr->ToString(0434));
      EXPECT_EQ("five hundred and fourty-five", convPtr->ToString(0545));
      EXPECT_EQ("six hundred and fifty-six", convPtr->ToString(0656));
      EXPECT_EQ("seven hundred and sixty-seven", convPtr->ToString(0767));
    }

    TEST_F(ConvTest, ThousandsEN8)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_EN, BASE_OCTAL));
      EXPECT_EQ("one thousand", convPtr->ToString(01000));
      EXPECT_EQ("one thousand and one", convPtr->ToString(01001));
      EXPECT_EQ("two hundred thousand and one", convPtr->ToString(0200001));
      EXPECT_EQ("three hundred and two thousand and one", convPtr->ToString(0302001));
      EXPECT_EQ("four hundred and thirty-two thousand five hundred and one", convPtr->ToString(0432501));
      EXPECT_EQ("one hundred and twenty-three thousand four hundred and fifty-six", convPtr->ToString(0123456));
      EXPECT_EQ("one hundred thousand", convPtr->ToString(0100000));
      EXPECT_EQ("seven hundred and seventy-seven thousand seven hundred and seventy-seven", convPtr->ToString(0777777));
      EXPECT_EQ("one hundred and thirteen thousand and one", convPtr->ToString(0113001));
    }

    TEST_F(ConvTest, MillionsEN8)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_EN, BASE_OCTAL));
      EXPECT_EQ("one million", convPtr->ToString(01000000));
      EXPECT_EQ("one million and one", convPtr->ToString(01000001));
      EXPECT_EQ("one hundred million", convPtr->ToString(0100 * 01000000));
      EXPECT_EQ("two hundred and ten million", convPtr->ToString(0210000000));
      EXPECT_EQ("three hundred and twenty-one million one hundred and twenty-three", convPtr->ToString(0321000123));
      EXPECT_EQ("one hundred and twenty-three million four hundred and fifty-six thousand seven hundred and sixty-five", convPtr->ToString(0123456765));
      EXPECT_EQ("one hundred and three million and six thousand and seven", convPtr->ToString(0103006007));
      EXPECT_EQ("twelve million and thirty-four thousand and fifty-six", convPtr->ToString(012034056));
      EXPECT_EQ("one million one hundred and twenty-three thousand and one", convPtr->ToString(01123001));
      EXPECT_EQ("one million and twelve", convPtr->ToString(01000012));
      EXPECT_EQ("one million one hundred", convPtr->ToString(01000100));
      EXPECT_EQ("one million one hundred and one", convPtr->ToString(01000101));
    }

    TEST_F(ConvTest, BillionsEN8)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_EN, BASE_OCTAL));
      EXPECT_EQ("one billion", convPtr->ToString(01000000000));
      EXPECT_EQ("one billion and one", convPtr->ToString(01000000001));
      EXPECT_EQ("one billion and twelve", convPtr->ToString(01000000012));
      EXPECT_EQ("one billion one hundred and one", convPtr->ToString(01000000101));
      EXPECT_EQ("one billion one hundred and twenty-three thousand and one", convPtr->ToString(01000123001));
      EXPECT_EQ("one billion one hundred and twenty-three million and one", convPtr->ToString(01123000001));
      EXPECT_EQ("one billion and twenty-three million and one", convPtr->ToString(01023000001));
      EXPECT_EQ("one billion and twenty-three thousand and one", convPtr->ToString(01000023001));
    }

    TEST_F(ConvTest, ZeroRU8)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_RU, BASE_OCTAL));
      EXPECT_EQ(std::string("ноль"), convPtr->ToString(00));
    }

    TEST_F(ConvTest, OnesRU8)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_RU, BASE_OCTAL));
      EXPECT_EQ("один", convPtr->ToString(01));
      EXPECT_EQ("два", convPtr->ToString(02));
      EXPECT_EQ("три", convPtr->ToString(03));
      EXPECT_EQ("четыре", convPtr->ToString(04));
      EXPECT_EQ("пять", convPtr->ToString(05));
      EXPECT_EQ("шесть", convPtr->ToString(06));
      EXPECT_EQ("семь", convPtr->ToString(07));
    }

    TEST_F(ConvTest, TeensRU8)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_RU, BASE_OCTAL));
      EXPECT_EQ("десять", convPtr->ToString(010));
      EXPECT_EQ("одиннадцать", convPtr->ToString(011));
      EXPECT_EQ("двенадцать", convPtr->ToString(012));
      EXPECT_EQ("тринадцать", convPtr->ToString(013));
      EXPECT_EQ("четырнадцать", convPtr->ToString(014));
      EXPECT_EQ("пятнадцать", convPtr->ToString(015));
      EXPECT_EQ("шестнадцать", convPtr->ToString(016));
      EXPECT_EQ("семнадцать", convPtr->ToString(017));
    }

    TEST_F(ConvTest, TwoDigitRU8)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_RU, BASE_OCTAL));
      EXPECT_EQ("двадцать", convPtr->ToString(020));
      EXPECT_EQ("тридцать один", convPtr->ToString(031));
      EXPECT_EQ("сорок два", convPtr->ToString(042));
      EXPECT_EQ("пятьдесят три", convPtr->ToString(053));
      EXPECT_EQ("шестьдесят четыре", convPtr->ToString(064));
      EXPECT_EQ("семьдесят пять", convPtr->ToString(075));
    }

    TEST_F(ConvTest, ThreeDigitRU8)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_RU, BASE_OCTAL));
      EXPECT_EQ("сто", convPtr->ToString(0100));
      EXPECT_EQ("сто один", convPtr->ToString(0101));
      EXPECT_EQ("двести двенадцать", convPtr->ToString(0212));
      EXPECT_EQ("триста двадцать три", convPtr->ToString(0323));
      EXPECT_EQ("четыреста тридцать четыре", convPtr->ToString(0434));
      EXPECT_EQ("пятьсот сорок пять", convPtr->ToString(0545));
      EXPECT_EQ("шестьсот пятьдесят шесть", convPtr->ToString(0656));
      EXPECT_EQ("семьсот шестьдесят семь", convPtr->ToString(0767));
    }

    TEST_F(ConvTest, ThousandsRU8)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_RU, BASE_OCTAL));
      EXPECT_EQ("одна тысяча", convPtr->ToString(01000));
      EXPECT_EQ("одна тысяча один", convPtr->ToString(01001));
      EXPECT_EQ("двести тысяч один", convPtr->ToString(0200001));
      EXPECT_EQ("триста две тысячи один", convPtr->ToString(0302001));
      EXPECT_EQ("четыреста тридцать две тысячи пятьсот один", convPtr->ToString(0432501));
      EXPECT_EQ("сто двадцать три тысячи четыреста пятьдесят шесть", convPtr->ToString(0123456));
      EXPECT_EQ("сто тысяч", convPtr->ToString(0100000));
      EXPECT_EQ("семьсот семьдесят семь тысяч семьсот семьдесят семь", convPtr->ToString(0777777));
      EXPECT_EQ("сто тринадцать тысяч один", convPtr->ToString(0113001));
    }

    TEST_F(ConvTest, MillionsRU8)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_RU, BASE_OCTAL));
      EXPECT_EQ("один миллион", convPtr->ToString(01000000));
      EXPECT_EQ("один миллион один", convPtr->ToString(01000001));
      EXPECT_EQ("сто миллионов", convPtr->ToString(0100 * 01000000));
      EXPECT_EQ("двести десять миллионов", convPtr->ToString(0210000000));
      EXPECT_EQ("триста двадцать один миллион сто двадцать три", convPtr->ToString(0321000123));
      EXPECT_EQ("сто двадцать три миллиона четыреста пятьдесят шесть тысяч семьсот шестьдесят пять", convPtr->ToString(0123456765));
      EXPECT_EQ("сто три миллиона шесть тысяч семь", convPtr->ToString(0103006007));
      EXPECT_EQ("двенадцать миллионов тридцать четыре тысячи пятьдесят шесть", convPtr->ToString(012034056));
      EXPECT_EQ("один миллион сто двадцать три тысячи один", convPtr->ToString(01123001));
      EXPECT_EQ("один миллион двенадцать", convPtr->ToString(01000012));
      EXPECT_EQ("один миллион сто", convPtr->ToString(01000100));
      EXPECT_EQ("один миллион сто один", convPtr->ToString(01000101));
    }

    TEST_F(ConvTest, BillionsRU8)
    {
      std::auto_ptr<Converter::NumericConverter> convPtr(GetFactory()->Get(LANG_RU, BASE_OCTAL));
      EXPECT_EQ("один миллиард", convPtr->ToString(01000000000));
      EXPECT_EQ("один миллиард один", convPtr->ToString(01000000001));
      EXPECT_EQ("один миллиард двенадцать", convPtr->ToString(01000000012));
      EXPECT_EQ("один миллиард сто один", convPtr->ToString(01000000101));
      EXPECT_EQ("один миллиард сто двадцать три тысячи один", convPtr->ToString(01000123001));
      EXPECT_EQ("один миллиард сто двадцать три миллиона один", convPtr->ToString(01123000001));
      EXPECT_EQ("один миллиард двадцать три миллиона один", convPtr->ToString(01023000001));
      EXPECT_EQ("один миллиард двадцать три тысячи один", convPtr->ToString(01000023001));
    }
  }
}