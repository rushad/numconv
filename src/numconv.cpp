#include "numconv.h"
#include <iostream>
#include <stack>

namespace Converter
{
  namespace Constants
  {
    static const std::string Space(" ");
    static const std::string Hyphen("-");

    namespace English
    {
      static const char* Zero = "zero";
      static const char* Ones[]   = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
      static const char* Teens[]  = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
      static const char* Tens[]   = { "", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
      static const char* GroupUnits[] = { "", "thousand", "million", "billion" };
      static const std::string Hundred("hundred");
      static const std::string And(" and ");
    }

    namespace Russian
    {
      static const char* Zero = "ноль";
      static const char* Ones[]   = { "", "один", "два", "три", "четыре", "п€ть", "шесть", "семь", "восемь", "дев€ть" };
      static const char* OnesF[]  = { "", "одна", "две" };
      static const char* Teens[]  = { "дес€ть", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать",
                                      "п€тнадцать", "шестнадцать", "семнадцать", "восемнадцать", "дев€тнадцать" };
      static const char* Tens[]   = { "", "", "двадцать", "тридцать", "сорок", "п€тьдес€т", 
                                      "шестьдес€т", "семьдес€т", "восемьдес€т", "дев€носто" };
      static const char* Hundreds[10] = { "", "сто", "двести", "триста", "четыреста", "п€тьсот",
                                          "шестьсот", "семьсот", "восемьсот", "дев€тьсот" };
      static const char* Thousands[3] = { "тыс€ча", "тыс€чи", "тыс€ч" };
    }
  }

  std::string Concat(const std::string& str1, const std::string& str2, const std::string& delim)
  {
    return str1 + ((!str1.empty() && !str2.empty()) ? delim : "") + str2;
  }

  std::string PluralFormRU(unsigned num, const char** forms)
  {
    if (num == 1)
      return forms[0];
    else if (num > 1 && num < 5)
      return forms[1];
    else
      return forms[2];
  }

  UIntToString::UIntToString(const LANG lang, const BASE base)
    : Lang(lang)
    , Base(base == BASE_OCTAL ? 8 : 10)
    , BaseTwenty(Base * 2)
    , BaseHundred(Base * Base)
    , BaseThousand(Base * Base * Base)
  {
  }

  std::string UIntToString::operator() (const unsigned num) const
  {
    if(Lang == LANG_ENGLISH)
      return ConvertEN(num, false);
    else 
      return ConvertRU(num, false, false);
  }

  bool UIntToString::InRange1To99(const unsigned num) const
  {
    return (num > 0) && (num < BaseHundred);
  }

  unsigned UIntToString::GroupUnit(const unsigned group) const
  {
    unsigned groupUnit = BaseThousand;
    for (unsigned i = 0; i < group - 1; ++i)
    {
      groupUnit *= BaseThousand;
    }

    return groupUnit;
  }

  std::string UIntToString::ConvertGroupEN(const unsigned num, const unsigned group) const
  {
    std::stack<unsigned> groups;

    for (unsigned div = num, i = 0; i <= group - 1; ++i)
    {
      groups.push(div % BaseThousand);
      div /= BaseThousand;
    }

    bool needAnd = false;
    while (!groups.empty())
    {
      if (groups.top())
      {
        needAnd = InRange1To99(groups.top());
        break;
      }

      groups.pop();
    }

    unsigned groupUnit = GroupUnit(group);

    return Concat(
      ConvertEN(num / groupUnit, true) + Constants::Space + Constants::English::GroupUnits[group],
      ConvertEN(num % groupUnit, true),
      needAnd ? Constants::English::And : Constants::Space);
  }

  std::string UIntToString::ConvertEN(const unsigned num, const bool skipZero) const
  {
    if (!num)
    {
      return skipZero ? "" : Constants::English::Zero;
    }
    else if (num < Base)
    {
      return Constants::English::Ones[num];
    }
    else if (num < BaseTwenty)
    {
      return Constants::English::Teens[num - Base];
    }
    else if (num < BaseHundred)
    {
      return Concat(Constants::English::Tens[num / Base], Constants::English::Ones[num % Base], Constants::Hyphen);
    }
    else if (num < BaseThousand)
    {
      return Concat(
        std::string(Constants::English::Ones[num / BaseHundred]) + Constants::Space + Constants::English::Hundred,
        ConvertEN(num % BaseHundred, true),
        Constants::English::And);
    }
    else if (num < BaseThousand * BaseThousand)
    {
      return ConvertGroupEN(num, 1);
    }
    else if (num < BaseThousand * BaseThousand * BaseThousand)
    {
      return ConvertGroupEN(num, 2);
    }
    else
    {
      return ConvertGroupEN(num, 3);
    }
  }

  std::string UIntToString::ConvertRU(const unsigned num, const bool skipZero, const bool feminine) const
  {
    if (!num)
    {
      return skipZero ? "" : Constants::Russian::Zero;
    }
    else if (num < Base)
    {
      if(feminine && num < 3)
      {
        return Constants::Russian::OnesF[num];
      }

      return Constants::Russian::Ones[num];
    }
    else if (num < BaseTwenty)
    {
      return Constants::Russian::Teens[num - Base];
    }
    else if (num < BaseHundred)
    {
      return Concat(Constants::Russian::Tens[num / Base], ConvertRU(num % Base, skipZero, feminine), Constants::Space);
    }
    else if (num < BaseThousand)
    {
      return Concat(
        Constants::Russian::Hundreds[num / BaseHundred],
        ConvertRU(num % BaseHundred, true, feminine),
        Constants::Space);
    }
    else if (num < BaseThousand * BaseThousand)
    {
      return Concat(
        ConvertRU(num / BaseThousand, true, true) + Constants::Space + PluralFormRU(num / BaseThousand % Base, Constants::Russian::Thousands),
        ConvertRU(num % BaseThousand, true, feminine),
        Constants::Space);
    }
    else
    {
      throw std::exception("num out of range");
    }
  }
}
