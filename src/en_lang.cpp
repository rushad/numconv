#include "numconv.h"

#include <stack>

namespace Converter
{
  namespace Constants
  {
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
  }

  NumericConverter* EnglishNumericConverter::createInstance(const BASE base)
  {
    return new EnglishNumericConverter(base);
  }

  EnglishNumericConverter::EnglishNumericConverter(const BASE base)
    : NumericConverter(base)
  {
  }

  std::string EnglishNumericConverter::ConvertToString(const unsigned num) const
  {
    return Convert(num, false);
  }

  bool EnglishNumericConverter::InRange1To99(const unsigned num) const
  {
    return (num > 0) && (num < BaseHundred);
  }

  unsigned EnglishNumericConverter::GroupUnit(const unsigned group) const
  {
    unsigned groupUnit = BaseThousand;
    for (unsigned i = 0; i < group - 1; ++i)
    {
      groupUnit *= BaseThousand;
    }

    return groupUnit;
  }


  std::string EnglishNumericConverter::ConvertGroup(const unsigned num, const unsigned group) const
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
      Convert(num / groupUnit, true) + Constants::Space + Constants::English::GroupUnits[group],
      Convert(num % groupUnit, true),
      needAnd ? Constants::English::And : Constants::Space);
  }

  std::string EnglishNumericConverter::Convert(const unsigned num, const bool skipZero) const
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
        Convert(num % BaseHundred, true),
        Constants::English::And);
    }
    else if (num < BaseThousand * BaseThousand)
    {
      return ConvertGroup(num, 1);
    }
    else if (num < BaseThousand * BaseThousand * BaseThousand)
    {
      return ConvertGroup(num, 2);
    }
    else
    {
      return ConvertGroup(num, 3);
    }
  }

}