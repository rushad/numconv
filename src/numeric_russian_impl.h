#pragma once

#include "converter.h"
#include "numeric.h"
#include "utils.h"

namespace Converter
{
  class NumericRussian : public Numeric
  {
  public:
    virtual std::string ToString(const unsigned num) const;

  private:
    explicit NumericRussian(const BASE base);
  
    std::string PluralForm(const unsigned num, const std::string* forms) const;
    std::string Convert(const unsigned num, const bool skipZero, const bool feminine) const;

    const Utils::BaseLimits Limits;

    static const std::string Zero;
    static const std::string Ones[];
    static const std::string OnesF[];
    static const std::string Teens[];
    static const std::string Tens[];
    static const std::string Hundreds[10];
    static const std::string Thousands[3];
    static const std::string Millions[3];
    static const std::string Billions[3];

    friend Numeric* CreateNumericRussian(const BASE base);
  };
}