#include "numeric_russian_impl.h"

namespace Converter
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
  const std::string NumericRussian::Thousands[3] = 
    { "������", "������", "�����" };
  const std::string NumericRussian::Millions[3] = 
    { "�������", "��������", "���������" };
  const std::string NumericRussian::Billions[3] = 
    { "��������", "���������", "����������" };

  Numeric* CreateNumericRussian(const BASE base)
  {
    return new NumericRussian(base);
  }

  NumericRussian::NumericRussian(const BASE base)
    : Limits(base)
  {
  }

  std::string NumericRussian::ToString(const unsigned num) const
  {
    return Convert(num, false, false);
  }

  std::string NumericRussian::PluralForm(const unsigned num, const std::string* forms) const
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


  std::string NumericRussian::Convert(const unsigned num, const bool skipZero, const bool feminine) const
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
    else if (num < Limits.BaseThousand())
    {
      return Utils::Concat(
        Hundreds[num / Limits.BaseHundred()],
        Convert(num % Limits.BaseHundred(), true, feminine),
        Constants::Space);
    }
    else if (num < Limits.BaseThousand() * Limits.BaseThousand())
    {
      return Utils::Concat(
        Convert(num / Limits.BaseThousand(), true, true) + Constants::Space + PluralForm(num / Limits.BaseThousand(), Thousands),
        Convert(num % Limits.BaseThousand(), true, feminine),
        Constants::Space);
    }
    else if (num < Limits.BaseThousand() * Limits.BaseThousand() * Limits.BaseThousand())
    {
      unsigned millions = num / (Limits.BaseThousand() * Limits.BaseThousand());
      return Utils::Concat(
        Convert(millions, true, false) + Constants::Space + PluralForm(millions, Millions),
        Convert(num % (Limits.BaseThousand() * Limits.BaseThousand()), true, feminine),
        Constants::Space);
    }
    else
    {
      unsigned billions = num / (Limits.BaseThousand() * Limits.BaseThousand() * Limits.BaseThousand());
      return Utils::Concat(
        Convert(billions, true, false) + Constants::Space + PluralForm(billions, Billions),
        Convert(num % (Limits.BaseThousand() * Limits.BaseThousand() * Limits.BaseThousand()), true, feminine),
        Constants::Space);
    }
  }
}