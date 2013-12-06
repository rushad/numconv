#pragma once

#include "converter.h"
#include "numeric.h"
#include "numeric_factory.h"

namespace Converter
{
  class NumericRussian : public Numeric
  {
  public:
    static Numeric* CreateInstance(const BASE base);

    virtual std::string ToString(const unsigned num) const;

  private:
    explicit NumericRussian(const BASE base);
  
    std::string PluralForm(const unsigned num, const std::string* forms) const;
    std::string Convert(const unsigned num, const bool skipZero, const bool feminine) const;

    const BaseLimits Limits;

    static const std::string Zero;
    static const std::string Ones[];
    static const std::string OnesF[];
    static const std::string Teens[];
    static const std::string Tens[];
    static const std::string Hundreds[10];
    static const std::string Thousands[3];
    static const std::string Millions[3];
    static const std::string Billions[3];
  };
}