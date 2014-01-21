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
      enum Gender { GENDER_MASCULINE, GENDER_FEMININE };
      struct GroupProps
      {
        GroupForms Forms;
        Gender Gender;
      };
      std::string PluralForm(const unsigned num, const GroupForms& forms) const;
      std::string Convert(const unsigned num, const bool skipZero, const Gender gender) const;
      std::string ConvertGroup(const unsigned num, const bool skipZero, const Gender gender) const;
      std::string ComposeHighestGroupAndRemain(const unsigned group, const Gender groupGender, const GroupForms& forms, const unsigned remain) const;
      int GetRank(const unsigned num, unsigned& groupBase) const;
      bool IsFeminineDigit(const Gender groupGender, const unsigned digit) const;

      const Utils::BaseLimits Limits;

      static const std::string Zero;
      static const std::string Ones[];
      static const std::string OnesF[];
      static const std::string Teens[];
      static const std::string Tens[];
      static const std::string Hundreds[];

      static const unsigned MaxUint32 = 0xffffffff;
      static const int MaxGroup = 3;
      static const GroupProps Groups[MaxGroup];
    };
  }
}