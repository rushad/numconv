#include "numeric_russian_internal.h"

namespace Converter
{
  namespace Internal
  {
    const std::string NumericRussian::Zero("ноль");
    const std::string NumericRussian::Ones[] = 
    { "", "один", "два", "три", "четыре", "п€ть", "шесть", "семь", "восемь", "дев€ть" };
    const std::string NumericRussian::OnesF[] = 
    { "", "одна", "две" };
    const std::string NumericRussian::Teens[] = 
    { "дес€ть", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать",
    "п€тнадцать", "шестнадцать", "семнадцать", "восемнадцать", "дев€тнадцать" };
    const std::string NumericRussian::Tens[] = 
    { "", "", "двадцать", "тридцать", "сорок", "п€тьдес€т", 
    "шестьдес€т", "семьдес€т", "восемьдес€т", "дев€носто" };
    const std::string NumericRussian::Hundreds[] = 
    { "", "сто", "двести", "триста", "четыреста", "п€тьсот",
    "шестьсот", "семьсот", "восемьсот", "дев€тьсот" };

    const NumericRussian::GroupProps NumericRussian::Groups[MaxGroup] = {
      { { "тыс€ча", "тыс€чи", "тыс€ч" }, GENDER_FEMININE }, 
      { {"миллион", "миллиона", "миллионов" }, GENDER_MASCULINE },
      { { "миллиард", "миллиарда", "миллиардов" }, GENDER_MASCULINE }
    };

    NumericRussian::NumericRussian(const BASE base)
      : Limits(base)
    {
    }

    std::string NumericRussian::ToString(const unsigned num) const
    {
      if(num > MaxUint32)
        throw std::invalid_argument("Argument is out of range");

      return Convert(num, false, GENDER_MASCULINE);
    }

    std::string NumericRussian::PluralForm(const unsigned num, const GroupForms& forms) const
    {
      unsigned ones = num % Limits.Base();
      unsigned tens = (num % Limits.BaseHundred()) / Limits.Base();
      if (tens != 1)
      {
        if (ones == 1)
          return forms[0];
        else if (ones > 1 && ones < 5)
          return forms[1];
      }
      return forms[2];
    }

    bool NumericRussian::IsFeminineDigit(const Gender groupGender, const unsigned digit) const
    {
      if (groupGender != GENDER_FEMININE)
        return false;
      return (digit == 1) || (digit == 2);
    }

    std::string NumericRussian::ConvertGroup(const unsigned num, const bool skipZero, const Gender groupGender) const
    {
      if (!num)
      {
        return skipZero ? "" : Zero;
      }
      else if (num < Limits.Base())
      {
        return IsFeminineDigit(groupGender, num) ? OnesF[num] : Ones[num];
      }
      else if (num < Limits.BaseTwenty())
      {
        return Teens[num - Limits.Base()];
      }
      else if (num < Limits.BaseHundred())
      {
        return Utils::Concat(
          Tens[num / Limits.Base()],
          Convert(num % Limits.Base(), true, groupGender),
          Constants::Space);
      }
      else
      {
        return Utils::Concat(
          Hundreds[num / Limits.BaseHundred()],
          Convert(num % Limits.BaseHundred(), true, groupGender),
          Constants::Space);
      }
    }

    unsigned NumericRussian::GetRank(const unsigned num, unsigned& groupBase) const
    {
      int groupNo = 0;
      while(true)
      {
        if (groupNo == MaxGroup - 1)
        {
          break;
        }

        unsigned limit = groupBase * Limits.BaseThousand();
        if (num < limit)
        {
          break;
        }

        groupBase = limit;
        ++groupNo;
      }
      return groupNo;
    }

    std::string NumericRussian::Convert(const unsigned num, const bool skipZero, const Gender gender) const
    {
      unsigned groupBase = Limits.BaseThousand();

      if (num < groupBase)
      {
        return ConvertGroup(num, skipZero, gender);
      }

      unsigned groupNo = GetRank(num, groupBase);

      const unsigned group = num / groupBase;
      const unsigned remain = num % groupBase;
      return ComposeHighestGroupAndRemain(group, Groups[groupNo].Gender, Groups[groupNo].Forms, remain);
    }

    std::string NumericRussian::ComposeHighestGroupAndRemain(
      const unsigned group,
      const Gender groupGender,
      const GroupForms& forms,
      const unsigned remain) const
    {
      return Utils::Concat(
        Convert(group, true, groupGender) + Constants::Space + PluralForm(group, forms),
        Convert(remain, true, GENDER_MASCULINE),
        Constants::Space);
    }
  }

  NumericPtr CreateNumericRussian(const BASE base)
  {
    return NumericPtr(new Internal::NumericRussian(base));
  }

}