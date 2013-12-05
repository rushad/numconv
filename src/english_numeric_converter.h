#pragma once

#include "numeric_converter.h"
#include "converter_utils.h"

namespace Converter
{
  class EnglishNumericConverter : public NumericConverter
  {
  public:
    static NumericConverter* CreateInstance(const BASE base);

    virtual std::string ToString(const unsigned num) const;

  private:
    explicit EnglishNumericConverter(const BASE base);
  
    bool InRange1To99(const unsigned num) const;
    unsigned GroupUnit(const unsigned group) const;
    std::string ConvertGroup(const unsigned num, const unsigned group) const;
    std::string Convert(const unsigned num, const bool skipZero) const;

    const BaseLimits Limits;
  };
}
