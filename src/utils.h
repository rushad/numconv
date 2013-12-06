#pragma once

#include "converter.h"

namespace Converter
{
  namespace Utils
  {
    std::string Concat(const std::string& str1, const std::string& str2, const std::string& delim);

    class BaseLimits
    {
    public:
      BaseLimits(BASE base)
        : BaseValue(GetBaseValue(base))
      {
      }

      static unsigned GetBaseValue(BASE base);

      unsigned Base() const
      {
        return BaseValue;
      }

      unsigned BaseTwenty() const
      {
        return 2 * BaseValue;
      }

      unsigned BaseHundred() const
      {
        return BaseValue * BaseValue;
      }

      unsigned BaseThousand() const
      {
        return BaseValue * BaseValue * BaseValue;
      }

    private:
      const unsigned BaseValue;
    };

  }
}