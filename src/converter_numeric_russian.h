#pragma once

#include "converter.h"
#include "converter_numeric.h"
#include "converter_numeric_factory.h"

namespace Converter
{
  class Russian : public Numeric
  {
  public:
    static Numeric* CreateInstance(const BASE base);

    virtual std::string ToString(const unsigned num) const;

  private:
    explicit Russian(const BASE base);
  
    std::string PluralForm(const unsigned num, const char** forms) const;
    std::string Convert(const unsigned num, const bool skipZero, const bool feminine) const;

    const BaseLimits Limits;
  };
}