#ifndef NUMCONV_H
#define NUMCONV_H

#include <string>

namespace Converter
{
  std::string Concat(const std::string& str1, const std::string& str2, const std::string& delim);

  enum BASE
  {
    BASE_DECIMAL,
    BASE_OCTAL,
  };

  class UIntToString
  {
  public:
    explicit UIntToString(const BASE base = BASE_DECIMAL);
    std::string operator() (unsigned num);

  private:
    const unsigned Base;
    const unsigned BaseTwenty;
    const unsigned BaseHundred;
    const unsigned BaseThousand;
    const unsigned BaseMillion;
    const unsigned BaseBillion;
    std::string ConvertGroup(const unsigned num, bool skipZero);
  };
}
#endif // NUMCONV_H
