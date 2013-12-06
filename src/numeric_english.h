#pragma once

#include "converter.h"
#include "numeric.h"

namespace Converter
{
  class NumericEnglish : public Numeric
  {
  public:
    static Numeric* CreateInstance(const BASE base);

    virtual std::string ToString(const unsigned num) const;

  private:
    explicit NumericEnglish(const BASE base);
  
    bool InRange1To99(const unsigned num) const;
    unsigned GroupUnit(const unsigned group) const;
    std::string ConvertGroup(const unsigned num, const unsigned group) const;
    std::string Convert(const unsigned num, const bool skipZero) const;

    const BaseLimits Limits;

    static const std::string Zero;
    static const std::string Ones[];
    static const std::string Teens[];
    static const std::string Tens[];
    static const std::string GroupUnits[];
    static const std::string Hundred;;
    static const std::string And;;

  };
}
