#pragma once

#include "numeric_converter.h"
#include "numeric_converter_factory.h"
#include "converter_utils.h"

namespace Converter
{
  class RussianNumericConverter : public NumericConverter
  {
  public:
    static NumericConverter* CreateInstance(const BASE base);

    virtual std::string ToString(const unsigned num) const;

  private:
    explicit RussianNumericConverter(const BASE base);
  
    std::string PluralForm(const unsigned num, const char** forms) const;
    std::string Convert(const unsigned num, const bool skipZero, const bool feminine) const;

    const BaseLimits Limits;
  };
}