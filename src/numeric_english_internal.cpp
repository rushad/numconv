#include "numeric_english.h"
#include "numeric_english_internal.h"

#include <stack>

namespace Converter
{
  namespace Internal
  {
    const std::string NumericEnglish::And(" and ");
    const std::string NumericEnglish::Zero("zero");
    const std::string NumericEnglish::Hundred("hundred");
    const std::string NumericEnglish::Ones[] = 
    { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    const std::string NumericEnglish::Teens[] = 
    { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    const std::string NumericEnglish::Tens[] = 
    { "", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    const std::string NumericEnglish::GroupUnits[MaxGroup] = 
    { "thousand", "million", "billion" };

    NumericEnglish::NumericEnglish(const BASE base)
      : Limits(base)
    {
    }

    std::string NumericEnglish::ToString(const unsigned num) const
    {
      if(num > MaxUint32)
        throw std::invalid_argument("Argument is out of range");

      return Convert(num, false);
    }

    bool NumericEnglish::InRange1To99(const unsigned num) const
    {
      return (num > 0) && (num < Limits.BaseHundred());
    }

    unsigned NumericEnglish::GroupUnit(const unsigned group) const
    {
      unsigned groupUnit = Limits.BaseThousand();
      for (unsigned i = 0; i < group; ++i)
      {
        groupUnit *= Limits.BaseThousand();
      }

      return groupUnit;
    }


    std::string NumericEnglish::ConvertGroup(const unsigned num, const unsigned group) const
    {
      std::stack<unsigned> groups;

      for (unsigned div = num, i = 0; i <= group; ++i)
      {
        groups.push(div % Limits.BaseThousand());
        div /= Limits.BaseThousand();
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

      return Utils::Concat(
        Convert(num / groupUnit, true) + Constants::Space + GroupUnits[group],
        Convert(num % groupUnit, true),
        needAnd ? And : Constants::Space);
    }

    unsigned NumericEnglish::GetRank(const unsigned num) const
    {
      unsigned rank = 0;
      unsigned limit = Limits.BaseThousand() * Limits.BaseThousand();
      for(; rank < MaxGroup - 1; ++rank)
      {
        if(num < limit)
          break;
        limit *= Limits.BaseThousand();
      }

      return rank;      
    }

    std::string NumericEnglish::Convert(const unsigned num, const bool skipZero) const
    {
      if (!num)
      {
        return skipZero ? "" : Zero;
      }
      else if (num < Limits.Base())
      {
        return Ones[num];
      }
      else if (num < Limits.BaseTwenty())
      {
        return Teens[num - Limits.Base()];
      }
      else if (num < Limits.BaseHundred())
      {
        return Utils::Concat(Tens[num / Limits.Base()], Ones[num % Limits.Base()], Constants::Hyphen);
      }
      else if (num < Limits.BaseThousand())
      {
        return Utils::Concat(
          std::string(Ones[num / Limits.BaseHundred()]) + Constants::Space + Hundred,
          Convert(num % Limits.BaseHundred(), true),
          And);
      }

      return ConvertGroup(num, GetRank(num));
    }
  }

  NumericPtr CreateNumericEnglish(const BASE base)
  {
    return NumericPtr(new Internal::NumericEnglish(base));
  }
}
