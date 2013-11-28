#include "numconv.h"

namespace Converter
{
  namespace Constants
  {
    static const char* Zero = "zero";
    static const char* Ones[]   = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    static const char* Teens[]  = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    static const char* Tens[]  =  { "", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    static const std::string Hundred("hundred");
    static const std::string Thousand("thousand");
    static const std::string Million("million");
    static const std::string Space(" ");
    static const std::string And(" and ");
    static const std::string Hyphen("-");
  }

  std::string Concat(const std::string& str1, const std::string& str2, const std::string& delim)
   {
    return str1 + ((!str1.empty() && !str2.empty()) ? delim : "") + str2;
  }

  UIntToString::UIntToString(const BASE base)
    : Base(base == BASE_OCTAL ? 8 : 10),
      BaseTwenty(Base * 2),
      BaseHundred(Base * Base),
      BaseThousand(Base * Base * Base),
      BaseMillion(BaseThousand * BaseThousand),
      BaseBillion(BaseThousand * BaseMillion)
  {}

  std::string UIntToString::operator() (unsigned num)
  {
    return ConvertGroup(num, false);
  }

  std::string UIntToString::ConvertGroup(const unsigned num, bool skipZero)
  {
    if (!num)
    {
      return skipZero ? "" : Constants::Zero;
    }
    else if (num < Base)
    {
      return Constants::Ones[num];
    }
    else if (num < BaseTwenty)
    {
      return Constants::Teens[num - Base];
    }
    else if (num < BaseHundred)
    {
      return Concat(Constants::Tens[num / Base], Constants::Ones[num % Base], Constants::Hyphen);
    }
    else if (num < BaseThousand)
    {
      return Concat(
        std::string(Constants::Ones[num / BaseHundred]) + Constants::Space + Constants::Hundred,
        ConvertGroup(num % BaseHundred, true),
        Constants::And);
    }
    else if (num < BaseMillion)
    {
      unsigned remain = num % BaseThousand;
      return Concat(
        ConvertGroup(num / BaseThousand, true) + Constants::Space + Constants::Thousand,
        ConvertGroup(remain, true),
        remain < BaseHundred ? Constants::And : Constants::Space);
    }
    else if (num < BaseBillion)
    {
      unsigned remain = num % BaseMillion;
      unsigned nextGroup = remain / BaseThousand;
      return Concat(
        ConvertGroup(num / BaseMillion, true) + Constants::Space + Constants::Million,
        ConvertGroup(remain, true),
        (nextGroup && (nextGroup < BaseHundred)) ? Constants::And : Constants::Space);
    }
    else
    {
      throw std::exception("num out of range");
    }
  }
}

