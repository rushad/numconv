#include "numconv.h"

namespace Converter
{
  namespace Constants
  {
    const std::string Space(" ");
    const std::string Hyphen("-");
  }

  std::string Concat(const std::string& str1, const std::string& str2, const std::string& delim)
  {
    return str1 + ((!str1.empty() && !str2.empty()) ? delim : "") + str2;
  }

  NumericConverter::NumericConverter(const BASE base)
    : Base(base == BASE_OCTAL ? 8 : 10)
    , BaseTwenty(Base * 2)
    , BaseHundred(Base * Base)
    , BaseThousand(Base * Base * Base)
  {
  }

  std::string NumericConverter::ToString(const unsigned num) const
  {
    return ConvertToString(num);
  }

  void NumericConverterFactory::Add(const std::string& lang, CreateInstanceFunc func)
  {
    MapLangFuncs[lang] = func;
  }

  NumericConverter* NumericConverterFactory::Get(const std::string& lang, BASE base)
  {
    std::map<std::string, CreateInstanceFunc>::const_iterator i = MapLangFuncs.find(lang);
    if(i != MapLangFuncs.end())
      return i->second(base);
    return 0;
  }
}
