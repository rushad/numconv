#pragma once

#include "converter.h"
#include "numeric.h"
#include "utils.h"

namespace Converter
{
  namespace Internal
  {
    class NumericEnglish : public Numeric
    {
    public:
      virtual std::string ToString(const unsigned num) const;
      explicit NumericEnglish(const BASE base);

    private:
      bool InRange1To99(const unsigned num) const;
      unsigned GroupUnit(const unsigned group) const;
      std::string ConvertGroup(const unsigned num, const unsigned group) const;
      unsigned GetRank(const unsigned num) const;
      std::string Convert(const unsigned num, const bool skipZero) const;

      const Utils::BaseLimits Limits;

      static const unsigned MaxUint32 = 0xffffffff;
      static const int MaxGroup = 3;

      static const std::string Zero;
      static const std::string Ones[];
      static const std::string Teens[];
      static const std::string Tens[];
      static const std::string GroupUnits[MaxGroup];
      static const std::string Hundred;
      static const std::string And;
    };
  }
}
