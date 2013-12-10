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
    const std::string NumericRussian::Hundreds[10] = 
    { "", "сто", "двести", "триста", "четыреста", "п€тьсот",
    "шестьсот", "семьсот", "восемьсот", "дев€тьсот" };

    const NumericRussian::GroupForms NumericRussian::ThousandForms = { "тыс€ча", "тыс€чи", "тыс€ч" };
    const bool ThousandGender = true;

    const NumericRussian::GroupForms NumericRussian::MillionForms = { "миллион", "миллиона", "миллионов" };
    const bool MillionGender = false;

    const NumericRussian::GroupForms NumericRussian::BillionForms = { "миллиард", "миллиарда", "миллиардов" };
    const bool BillionGender = false;

    const bool MasculineGender = false;

    NumericRussian::NumericRussian(const BASE base)
      : Limits(base)
    {
    }

    std::string NumericRussian::ToString(const unsigned num) const
    {
      return Convert(num, false, false);
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

    std::string NumericRussian::ConvertGroup(const unsigned num, const bool skipZero, const bool feminine) const
    {
      if (!num)
      {
        return skipZero ? "" : Zero;
      }
      else if (num < Limits.Base())
      {
        if(feminine && num < 3)
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
        return Utils::Concat(Tens[num / Limits.Base()], Convert(num % Limits.Base(), true, feminine), Constants::Space);
      }
      else
      {
        return Utils::Concat(
          Hundreds[num / Limits.BaseHundred()],
          Convert(num % Limits.BaseHundred(), true, feminine),
          Constants::Space);
      }
    }

    std::string NumericRussian::Convert(const unsigned num, const bool skipZero, const bool feminine) const
    {
      if (num < Limits.BaseThousand())
      {
        return ConvertGroup(num, skipZero, feminine);
      }

      if (num < Limits.BaseThousand() * Limits.BaseThousand())
      {
        const unsigned groupBase = Limits.BaseThousand();
        const unsigned group = num / groupBase;
        const unsigned remain = num % groupBase;
        return ComposeHighestGroupAndRemain(group, ThousandGender, ThousandForms, remain);
      }
      else if (num < Limits.BaseThousand() * Limits.BaseThousand() * Limits.BaseThousand())
      {
        const unsigned groupBase = Limits.BaseThousand() * Limits.BaseThousand();
        const unsigned group = num / groupBase;
        const unsigned remain = num % groupBase;
        return ComposeHighestGroupAndRemain(group, MillionGender, MillionForms, remain);
      }
      else
      {
        const unsigned groupBase = Limits.BaseThousand() * Limits.BaseThousand() * Limits.BaseThousand();
        const unsigned group = num / groupBase;
        const unsigned remain = num % groupBase;
        return ComposeHighestGroupAndRemain(group, BillionGender, BillionForms, remain);
      }
    }

    std::string NumericRussian::ComposeHighestGroupAndRemain(
      const unsigned group,
      const bool groupGender,
      const GroupForms& forms,
      const unsigned remain) const
    {
      return Utils::Concat(
        Convert(group, true, groupGender) + Constants::Space + PluralForm(group, forms),
        Convert(remain, true, MasculineGender),
        Constants::Space);
    }
  }

  NumericPtr CreateNumericRussian(const BASE base)
  {
    return NumericPtr(new Internal::NumericRussian(base));
  }

}