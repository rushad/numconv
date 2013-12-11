#include "numeric_russian_internal.h"

namespace Converter
{
  namespace Internal
  {
    const std::string NumericRussian::Zero("����");
    const std::string NumericRussian::Ones[] = 
    { "", "����", "���", "���", "������", "����", "�����", "����", "������", "������" };
    const std::string NumericRussian::OnesF[] = 
    { "", "����", "���" };
    const std::string NumericRussian::Teens[] = 
    { "������", "�����������", "����������", "����������", "������������",
    "����������", "�����������", "����������", "������������", "������������" };
    const std::string NumericRussian::Tens[] = 
    { "", "", "��������", "��������", "�����", "���������", 
    "����������", "���������", "�����������", "���������" };
    const std::string NumericRussian::Hundreds[10] = 
    { "", "���", "������", "������", "���������", "�������",
    "��������", "�������", "���������", "���������" };

    const NumericRussian::GroupProps NumericRussian::Groups[3] = {
      { { "������", "������", "�����" }, GENDER_FEMININE }, 
      { {"�������", "��������", "���������" }, GENDER_MASCULINE },
      { { "��������", "���������", "����������" }, GENDER_MASCULINE }
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

    std::string NumericRussian::ConvertGroup(const unsigned num, const bool skipZero, const Gender gender) const
    {
      if (!num)
      {
        return skipZero ? "" : Zero;
      }
      else if (num < Limits.Base())
      {
        if((gender == GENDER_FEMININE) && (num < 3))
        {
          return OnesF[num];
        }

        return Ones[num];
      }
      else if (num < Limits.BaseTwenty())
      {
        return Teens[num - Limits.Base()];
      }
      else if (num < Limits.BaseHundred())
      {
        return Utils::Concat(Tens[num / Limits.Base()], Convert(num % Limits.Base(), true, gender), Constants::Space);
      }
      else
      {
        return Utils::Concat(
          Hundreds[num / Limits.BaseHundred()],
          Convert(num % Limits.BaseHundred(), true, gender),
          Constants::Space);
      }
    }

    int NumericRussian::GetRank(const unsigned num, unsigned& groupBase) const
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

      int groupNo = GetRank(num, groupBase);

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