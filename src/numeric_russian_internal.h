#pragma once

#include "converter.h"
#include "numeric.h"
#include "utils.h"

namespace Converter
{
  namespace Internal
  {
    class NumericRussian : public Numeric
    {
    public:
      virtual std::string ToString(const unsigned num) const;
      explicit NumericRussian(const BASE base);

    private:
      typedef std::string GroupForms[3];
      std::string PluralForm(const unsigned num, const GroupForms& forms) const;
      std::string Convert(const unsigned num, const bool skipZero, const bool feminine) const;
      std::string ConvertGroup(const unsigned num, const bool skipZero, const bool feminine) const;
      std::string ComposeHighestGroupAndRemain(const unsigned group, const bool groupGender, const GroupForms& forms, const unsigned remain) const;

      const Utils::BaseLimits Limits;

      static const std::string Zero;
      static const std::string Ones[];
      static const std::string OnesF[];
      static const std::string Teens[];
      static const std::string Tens[];
      static const std::string Hundreds[10];

      static const GroupForms ThousandForms;
      static const GroupForms MillionForms;
      static const GroupForms BillionForms;
    };
  }
}