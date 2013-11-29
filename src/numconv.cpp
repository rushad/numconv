#include "numconv.h"

#include <stack>

namespace Converter
{
  namespace Constants
  {
    static const char* Zero = "zero";
    static const char* Ones[]   = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    static const char* Teens[]  = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    static const char* Tens[]  =  { "", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    static const char* GroupUnits[] = { "", "thousand", "million", "billion" };
    static const std::string Hundred("hundred");
    static const std::string Space(" ");
    static const std::string And(" and ");
    static const std::string Hyphen("-");
  }

  std::string Concat(const std::string& str1, const std::string& str2, const std::string& delim)
   {
    return str1 + ((!str1.empty() && !str2.empty()) ? delim : "") + str2;
  }

  UIntToString::UIntToString(const BASE base)
    : Base(base == BASE_OCTAL ? 8 : 10)
    , BaseTwenty(Base * 2)
    , BaseHundred(Base * Base)
    , BaseThousand(Base * Base * Base)
  {
  }

  std::string UIntToString::operator() (const unsigned num) const
  {
    return Convert(num, false);
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

  std::string UIntToString::ConvertGroup(const unsigned num, const unsigned group) const
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
      Convert(num / groupUnit, true) + Constants::Space + Constants::GroupUnits[group],
      Convert(num % groupUnit, true),
      needAnd ? Constants::And : Constants::Space);
  }

  std::string UIntToString::Convert(const unsigned num, const bool skipZero) const
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
        Convert(num % BaseHundred, true),
        Constants::And);
    }
    else if (num < BaseThousand * BaseThousand)
    {
      return ConvertGroup(num, 1);
    }
    else if (num < BaseThousand * BaseThousand * BaseThousand)
    {
      return ConvertGroup(num, 2);
    }
    else if (num < UINT_MAX)
    {
      return ConvertGroup(num, 3);
    }
    else
    {
      throw std::exception("num out of range");
    }
  }
}

