#pragma once

#include "numeric_converter_factory.h"

#include <string>
#include <map>

namespace Converter
{
  namespace Constants
  {
    extern const std::string Space;
    extern const std::string Hyphen;
  }

  std::string Concat(const std::string& str1, const std::string& str2, const std::string& delim);

  class BaseLimits
  {
  public:
    BaseLimits(BASE base)
      : BaseValue(GetBaseValue(base))
    {
    }

    static unsigned GetBaseValue(BASE base)
    {
      switch(base)
      {
      case BASE_DECIMAL:
        return 10;
      case BASE_OCTAL:
        return 8;
      default:
        throw std::exception("Wrong BASE value");
      }
    }

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
