#include "numconv.h"

namespace Converter
{
  namespace Constants
  {
    namespace Russian
    {
      static const char* Zero = "ноль";
      static const char* Ones[]   = { "", "один", "два", "три", "четыре", "п€ть", "шесть", "семь", "восемь", "дев€ть" };
      static const char* OnesF[]  = { "", "одна", "две" };
      static const char* Teens[]  = { "дес€ть", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать",
        "п€тнадцать", "шестнадцать", "семнадцать", "восемнадцать", "дев€тнадцать" };
      static const char* Tens[]   = { "", "", "двадцать", "тридцать", "сорок", "п€тьдес€т", 
        "шестьдес€т", "семьдес€т", "восемьдес€т", "дев€носто" };
      static const char* Hundreds[10] = { "", "сто", "двести", "триста", "четыреста", "п€тьсот",
        "шестьсот", "семьсот", "восемьсот", "дев€тьсот" };
      static const char* Thousands[3] = { "тыс€ча", "тыс€чи", "тыс€ч" };
      static const char* Millions[3]  = { "миллион", "миллиона", "миллионов" };
      static const char* Billions[3]  = { "миллиард", "миллиарда", "миллиардов" };
    }
  }

  NumericConverter* RussianNumericConverter::createInstance(const BASE base)
  {
    return new RussianNumericConverter(base);
  }

  RussianNumericConverter::RussianNumericConverter(const BASE base)
    : Limits(base)
  {
  }

  std::string RussianNumericConverter::ToString(const unsigned num) const
  {
    return Convert(num, false, false);
  }

  std::string RussianNumericConverter::PluralForm(const unsigned num, const char** forms) const
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


  std::string RussianNumericConverter::Convert(const unsigned num, const bool skipZero, const bool feminine) const
  {
    if (!num)
    {
      return skipZero ? "" : Constants::Russian::Zero;
    }
    else if (num < Limits.Base())
    {
      if(feminine && num < 3)
      {
        return Constants::Russian::OnesF[num];
      }

      return Constants::Russian::Ones[num];
    }
    else if (num < Limits.BaseTwenty())
    {
      return Constants::Russian::Teens[num - Limits.Base()];
    }
    else if (num < Limits.BaseHundred())
    {
      return Concat(Constants::Russian::Tens[num / Limits.Base()], Convert(num % Limits.Base(), true, feminine), Constants::Space);
    }
    else if (num < Limits.BaseThousand())
    {
      return Concat(
        Constants::Russian::Hundreds[num / Limits.BaseHundred()],
        Convert(num % Limits.BaseHundred(), true, feminine),
        Constants::Space);
    }
    else if (num < Limits.BaseThousand() * Limits.BaseThousand())
    {
      return Concat(
        Convert(num / Limits.BaseThousand(), true, true) + Constants::Space + PluralForm(num / Limits.BaseThousand(), Constants::Russian::Thousands),
        Convert(num % Limits.BaseThousand(), true, feminine),
        Constants::Space);
    }
    else if (num < Limits.BaseThousand() * Limits.BaseThousand() * Limits.BaseThousand())
    {
      unsigned millions = num / (Limits.BaseThousand() * Limits.BaseThousand());
      return Concat(
        Convert(millions, true, false) + Constants::Space + PluralForm(millions, Constants::Russian::Millions),
        Convert(num % (Limits.BaseThousand() * Limits.BaseThousand()), true, feminine),
        Constants::Space);
    }
    else
    {
      unsigned billions = num / (Limits.BaseThousand() * Limits.BaseThousand() * Limits.BaseThousand());
      return Concat(
        Convert(billions, true, false) + Constants::Space + PluralForm(billions, Constants::Russian::Billions),
        Convert(num % (Limits.BaseThousand() * Limits.BaseThousand() * Limits.BaseThousand()), true, feminine),
        Constants::Space);
    }
  }
}