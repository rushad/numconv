#include "numconv.h"

namespace Converter
{
  namespace Constants
  {
    namespace Russian
    {
      static const char* Zero = "����";
      static const char* Ones[]   = { "", "����", "���", "���", "������", "����", "�����", "����", "������", "������" };
      static const char* OnesF[]  = { "", "����", "���" };
      static const char* Teens[]  = { "������", "�����������", "����������", "����������", "������������",
        "����������", "�����������", "����������", "������������", "������������" };
      static const char* Tens[]   = { "", "", "��������", "��������", "�����", "���������", 
        "����������", "���������", "�����������", "���������" };
      static const char* Hundreds[10] = { "", "���", "������", "������", "���������", "�������",
        "��������", "�������", "���������", "���������" };
      static const char* Thousands[3] = { "������", "������", "�����" };
      static const char* Millions[3]  = { "�������", "��������", "���������" };
      static const char* Billions[3]  = { "��������", "���������", "����������" };
    }
  }

  NumericConverter* RussianNumericConverter::createInstance(const BASE base)
  {
    return new RussianNumericConverter(base);
  }

  RussianNumericConverter::RussianNumericConverter(const BASE base)
    : NumericConverter(base)
  {
  }

  std::string RussianNumericConverter::ConvertToString(const unsigned num) const
  {
    return Convert(num, false, false);
  }

  std::string RussianNumericConverter::PluralForm(const unsigned num, const char** forms) const
  {
    unsigned ones = num % Base;
    unsigned tens = (num % BaseHundred) / Base;
    if (tens != 1)
    {
      if (ones == 1)
        return forms[0];
      else if (ones > 1 && ones < 5)
        return forms[1];
    }
    return forms[2];
  }


  std::string RussianNumericConverter::Convert(const unsigned num, const bool skipZero, const bool feminine) const
  {
    if (!num)
    {
      return skipZero ? "" : Constants::Russian::Zero;
    }
    else if (num < Base)
    {
      if(feminine && num < 3)
      {
        return Constants::Russian::OnesF[num];
      }

      return Constants::Russian::Ones[num];
    }
    else if (num < BaseTwenty)
    {
      return Constants::Russian::Teens[num - Base];
    }
    else if (num < BaseHundred)
    {
      return Concat(Constants::Russian::Tens[num / Base], Convert(num % Base, true, feminine), Constants::Space);
    }
    else if (num < BaseThousand)
    {
      return Concat(
        Constants::Russian::Hundreds[num / BaseHundred],
        Convert(num % BaseHundred, true, feminine),
        Constants::Space);
    }
    else if (num < BaseThousand * BaseThousand)
    {
      return Concat(
        Convert(num / BaseThousand, true, true) + Constants::Space + PluralForm(num / BaseThousand, Constants::Russian::Thousands),
        Convert(num % BaseThousand, true, feminine),
        Constants::Space);
    }
    else if (num < BaseThousand * BaseThousand * BaseThousand)
    {
      unsigned millions = num / (BaseThousand * BaseThousand);
      return Concat(
        Convert(millions, true, false) + Constants::Space + PluralForm(millions, Constants::Russian::Millions),
        Convert(num % (BaseThousand * BaseThousand), true, feminine),
        Constants::Space);
    }
    else
    {
      unsigned billions = num / (BaseThousand * BaseThousand * BaseThousand);
      return Concat(
        Convert(billions, true, false) + Constants::Space + PluralForm(billions, Constants::Russian::Billions),
        Convert(num % (BaseThousand * BaseThousand * BaseThousand), true, feminine),
        Constants::Space);
    }
  }
}