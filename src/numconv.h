#ifndef NUMCONV_H
#define NUMCONV_H

#include <string>

namespace Converter
{
  std::string Concat(const std::string& str1, const std::string& str2, const std::string& delim);

  enum LANG
  {
    LANG_ENGLISH,
    LANG_RUSSIAN
  };

  enum BASE
  {
    BASE_DECIMAL,
    BASE_OCTAL,
  };

  class UIntToString
  {
  public:
    explicit UIntToString(const LANG lang, const BASE base = BASE_DECIMAL);
    std::string operator() (const unsigned num) const;

  private:
    const int Lang;
    const unsigned Base;
    const unsigned BaseTwenty;
    const unsigned BaseHundred;
    const unsigned BaseThousand;
    bool InRange1To99(const unsigned num) const;
    unsigned GroupUnit(const unsigned group) const;
    std::string ConvertGroupEN(const unsigned num, const unsigned group) const;
    std::string ConvertEN(const unsigned num, const bool skipZero) const;
    std::string ConvertRU(const unsigned num, const bool skipZero, const bool feminine) const;
  };
}
#endif // NUMCONV_H
