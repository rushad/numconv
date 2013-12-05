#pragma once

#include <string>

namespace Converter
{
  enum BASE
  {
    BASE_DECIMAL,
    BASE_OCTAL
  };

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
