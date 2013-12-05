#include "russian_numeric_converter.h"
#include "gtest/gtest.h"

namespace Converter
{
  namespace Test
  {
    class ConvTestRu : public ::testing::Test
    {
    public:
      ConvTestRu()
        : pConv10(RussianNumericConverter::CreateInstance(BASE_DECIMAL))
        , pConv8(RussianNumericConverter::CreateInstance(BASE_OCTAL))
      {
      }

    protected:
      std::auto_ptr<NumericConverter> pConv10;
      std::auto_ptr<NumericConverter> pConv8;
    };

    TEST_F(ConvTestRu, Zero10)
    {
      EXPECT_EQ(std::string("ноль"), pConv10->ToString(0));
    }

    TEST_F(ConvTestRu, Ones10)
    {
      EXPECT_EQ("один", pConv10->ToString(1));
      EXPECT_EQ("два", pConv10->ToString(2));
      EXPECT_EQ("три", pConv10->ToString(3));
      EXPECT_EQ("четыре", pConv10->ToString(4));
      EXPECT_EQ("пять", pConv10->ToString(5));
      EXPECT_EQ("шесть", pConv10->ToString(6));
      EXPECT_EQ("семь", pConv10->ToString(7));
      EXPECT_EQ("восемь", pConv10->ToString(8));
      EXPECT_EQ("девять", pConv10->ToString(9));
    }

    TEST_F(ConvTestRu, Teens10)
    {
      EXPECT_EQ("десять", pConv10->ToString(10));
      EXPECT_EQ("одиннадцать", pConv10->ToString(11));
      EXPECT_EQ("двенадцать", pConv10->ToString(12));
      EXPECT_EQ("тринадцать", pConv10->ToString(13));
      EXPECT_EQ("четырнадцать", pConv10->ToString(14));
      EXPECT_EQ("пятнадцать", pConv10->ToString(15));
      EXPECT_EQ("шестнадцать", pConv10->ToString(16));
      EXPECT_EQ("семнадцать", pConv10->ToString(17));
      EXPECT_EQ("восемнадцать", pConv10->ToString(18));
      EXPECT_EQ("девятнадцать", pConv10->ToString(19));
    }

    TEST_F(ConvTestRu, TwoDigit10)
    {
      EXPECT_EQ("двадцать", pConv10->ToString(20));
      EXPECT_EQ("тридцать один", pConv10->ToString(31));
      EXPECT_EQ("сорок два", pConv10->ToString(42));
      EXPECT_EQ("пятьдесят три", pConv10->ToString(53));
      EXPECT_EQ("шестьдесят четыре", pConv10->ToString(64));
      EXPECT_EQ("семьдесят пять", pConv10->ToString(75));
      EXPECT_EQ("восемьдесят шесть", pConv10->ToString(86));
      EXPECT_EQ("девяносто семь", pConv10->ToString(97));
    }

    TEST_F(ConvTestRu, ThreeDigit10)
    {
      EXPECT_EQ("сто", pConv10->ToString(100));
      EXPECT_EQ("сто один", pConv10->ToString(101));
      EXPECT_EQ("двести двенадцать", pConv10->ToString(212));
      EXPECT_EQ("триста двадцать три", pConv10->ToString(323));
      EXPECT_EQ("четыреста тридцать четыре", pConv10->ToString(434));
      EXPECT_EQ("пятьсот сорок пять", pConv10->ToString(545));
      EXPECT_EQ("шестьсот пятьдесят шесть", pConv10->ToString(656));
      EXPECT_EQ("семьсот шестьдесят семь", pConv10->ToString(767));
      EXPECT_EQ("восемьсот семьдесят восемь", pConv10->ToString(878));
      EXPECT_EQ("девятьсот восемьдесят девять", pConv10->ToString(989));
    }

    TEST_F(ConvTestRu, Thousands10)
    {
      EXPECT_EQ("одна тысяча", pConv10->ToString(1000));
      EXPECT_EQ("одна тысяча один", pConv10->ToString(1001));
      EXPECT_EQ("двести тысяч один", pConv10->ToString(200001));
      EXPECT_EQ("триста две тысячи один", pConv10->ToString(302001));
      EXPECT_EQ("четыреста тридцать две тысячи пятьсот один", pConv10->ToString(432501));
      EXPECT_EQ("сто двадцать три тысячи четыреста пятьдесят шесть", pConv10->ToString(123456));
      EXPECT_EQ("сто тысяч", pConv10->ToString(100000));
      EXPECT_EQ("девятьсот девяносто девять тысяч девятьсот девяносто девять", pConv10->ToString(999999));
      EXPECT_EQ("сто тринадцать тысяч один", pConv10->ToString(113001));
    }

    TEST_F(ConvTestRu, Millions10)
    {
      EXPECT_EQ("один миллион", pConv10->ToString(1000000));
      EXPECT_EQ("один миллион один", pConv10->ToString(1000001));
      EXPECT_EQ("сто миллионов", pConv10->ToString(100 * 1000000));
      EXPECT_EQ("двести десять миллионов", pConv10->ToString(210000000));
      EXPECT_EQ("триста двадцать один миллион сто двадцать три", pConv10->ToString(321000123));
      EXPECT_EQ("сто двадцать три миллиона четыреста пятьдесят шесть тысяч семьсот восемьдесят девять", pConv10->ToString(123456789));
      EXPECT_EQ("сто три миллиона шесть тысяч девять", pConv10->ToString(103006009));
      EXPECT_EQ("двенадцать миллионов тридцать четыре тысячи пятьдесят шесть", pConv10->ToString(12034056));
      EXPECT_EQ("один миллион сто двадцать три тысячи один", pConv10->ToString(1123001));
      EXPECT_EQ("один миллион двенадцать", pConv10->ToString(1000012));
      EXPECT_EQ("один миллион сто", pConv10->ToString(1000100));
      EXPECT_EQ("один миллион сто один", pConv10->ToString(1000101));
    }

    TEST_F(ConvTestRu, Billions10)
    {
      EXPECT_EQ("один миллиард", pConv10->ToString(1000000000));
      EXPECT_EQ("один миллиард один", pConv10->ToString(1000000001));
      EXPECT_EQ("один миллиард двенадцать", pConv10->ToString(1000000012));
      EXPECT_EQ("один миллиард сто один", pConv10->ToString(1000000101));
      EXPECT_EQ("один миллиард сто двадцать три тысячи один", pConv10->ToString(1000123001));
      EXPECT_EQ("один миллиард сто двадцать три миллиона один", pConv10->ToString(1123000001));
      EXPECT_EQ("один миллиард двадцать три миллиона один", pConv10->ToString(1023000001));
      EXPECT_EQ("один миллиард двадцать три тысячи один", pConv10->ToString(1000023001));
    }

    TEST_F(ConvTestRu, Zero8)
    {
      EXPECT_EQ(std::string("ноль"), pConv8->ToString(00));
    }

    TEST_F(ConvTestRu, Ones8)
    {
      EXPECT_EQ("один", pConv8->ToString(01));
      EXPECT_EQ("два", pConv8->ToString(02));
      EXPECT_EQ("три", pConv8->ToString(03));
      EXPECT_EQ("четыре", pConv8->ToString(04));
      EXPECT_EQ("пять", pConv8->ToString(05));
      EXPECT_EQ("шесть", pConv8->ToString(06));
      EXPECT_EQ("семь", pConv8->ToString(07));
    }

    TEST_F(ConvTestRu, Teens8)
    {
      EXPECT_EQ("десять", pConv8->ToString(010));
      EXPECT_EQ("одиннадцать", pConv8->ToString(011));
      EXPECT_EQ("двенадцать", pConv8->ToString(012));
      EXPECT_EQ("тринадцать", pConv8->ToString(013));
      EXPECT_EQ("четырнадцать", pConv8->ToString(014));
      EXPECT_EQ("пятнадцать", pConv8->ToString(015));
      EXPECT_EQ("шестнадцать", pConv8->ToString(016));
      EXPECT_EQ("семнадцать", pConv8->ToString(017));
    }

    TEST_F(ConvTestRu, TwoDigit8)
    {
      EXPECT_EQ("двадцать", pConv8->ToString(020));
      EXPECT_EQ("тридцать один", pConv8->ToString(031));
      EXPECT_EQ("сорок два", pConv8->ToString(042));
      EXPECT_EQ("пятьдесят три", pConv8->ToString(053));
      EXPECT_EQ("шестьдесят четыре", pConv8->ToString(064));
      EXPECT_EQ("семьдесят пять", pConv8->ToString(075));
    }

    TEST_F(ConvTestRu, ThreeDigit8)
    {
      EXPECT_EQ("сто", pConv8->ToString(0100));
      EXPECT_EQ("сто один", pConv8->ToString(0101));
      EXPECT_EQ("двести двенадцать", pConv8->ToString(0212));
      EXPECT_EQ("триста двадцать три", pConv8->ToString(0323));
      EXPECT_EQ("четыреста тридцать четыре", pConv8->ToString(0434));
      EXPECT_EQ("пятьсот сорок пять", pConv8->ToString(0545));
      EXPECT_EQ("шестьсот пятьдесят шесть", pConv8->ToString(0656));
      EXPECT_EQ("семьсот шестьдесят семь", pConv8->ToString(0767));
    }

    TEST_F(ConvTestRu, Thousands8)
    {
      EXPECT_EQ("одна тысяча", pConv8->ToString(01000));
      EXPECT_EQ("одна тысяча один", pConv8->ToString(01001));
      EXPECT_EQ("двести тысяч один", pConv8->ToString(0200001));
      EXPECT_EQ("триста две тысячи один", pConv8->ToString(0302001));
      EXPECT_EQ("четыреста тридцать две тысячи пятьсот один", pConv8->ToString(0432501));
      EXPECT_EQ("сто двадцать три тысячи четыреста пятьдесят шесть", pConv8->ToString(0123456));
      EXPECT_EQ("сто тысяч", pConv8->ToString(0100000));
      EXPECT_EQ("семьсот семьдесят семь тысяч семьсот семьдесят семь", pConv8->ToString(0777777));
      EXPECT_EQ("сто тринадцать тысяч один", pConv8->ToString(0113001));
    }

    TEST_F(ConvTestRu, Millions8)
    {
      EXPECT_EQ("один миллион", pConv8->ToString(01000000));
      EXPECT_EQ("один миллион один", pConv8->ToString(01000001));
      EXPECT_EQ("сто миллионов", pConv8->ToString(0100 * 01000000));
      EXPECT_EQ("двести десять миллионов", pConv8->ToString(0210000000));
      EXPECT_EQ("триста двадцать один миллион сто двадцать три", pConv8->ToString(0321000123));
      EXPECT_EQ("сто двадцать три миллиона четыреста пятьдесят шесть тысяч семьсот шестьдесят пять", pConv8->ToString(0123456765));
      EXPECT_EQ("сто три миллиона шесть тысяч семь", pConv8->ToString(0103006007));
      EXPECT_EQ("двенадцать миллионов тридцать четыре тысячи пятьдесят шесть", pConv8->ToString(012034056));
      EXPECT_EQ("один миллион сто двадцать три тысячи один", pConv8->ToString(01123001));
      EXPECT_EQ("один миллион двенадцать", pConv8->ToString(01000012));
      EXPECT_EQ("один миллион сто", pConv8->ToString(01000100));
      EXPECT_EQ("один миллион сто один", pConv8->ToString(01000101));
    }

    TEST_F(ConvTestRu, Billions8)
    {
      EXPECT_EQ("один миллиард", pConv8->ToString(01000000000));
      EXPECT_EQ("один миллиард один", pConv8->ToString(01000000001));
      EXPECT_EQ("один миллиард двенадцать", pConv8->ToString(01000000012));
      EXPECT_EQ("один миллиард сто один", pConv8->ToString(01000000101));
      EXPECT_EQ("один миллиард сто двадцать три тысячи один", pConv8->ToString(01000123001));
      EXPECT_EQ("один миллиард сто двадцать три миллиона один", pConv8->ToString(01123000001));
      EXPECT_EQ("один миллиард двадцать три миллиона один", pConv8->ToString(01023000001));
      EXPECT_EQ("один миллиард двадцать три тысячи один", pConv8->ToString(01000023001));
    }
  }
}