#pragma once

#include "converter.h"
#include "converter_numeric.h"

namespace Converter
{
  class English : public Numeric
  {
  public:
    static Numeric* CreateInstance(const BASE base);

    virtual std::string ToString(const unsigned num) const;

  private:
    explicit English(const BASE base);
  
    bool InRange1To99(const unsigned num) const;
    unsigned GroupUnit(const unsigned group) const;
    std::string ConvertGroup(const unsigned num, const unsigned group) const;
    std::string Convert(const unsigned num, const bool skipZero) const;

    const BaseLimits Limits;
  };
}
