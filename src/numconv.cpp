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

  void NumericConverterFactory::Add(const std::string& lang, CreateInstanceFunc func)
  {
    if(!func)
      throw std::invalid_argument("NULL CreateInstance not allowed");

    std::map<std::string, CreateInstanceFunc>::const_iterator i = MapLangFuncs.find(lang);
    if(i != MapLangFuncs.end())
      throw std::invalid_argument("Language " + lang + " is already defined");

    MapLangFuncs[lang] = func;
  }

  NumericConverter* NumericConverterFactory::Get(const std::string& lang, BASE base)
  {
    std::map<std::string, CreateInstanceFunc>::const_iterator i = MapLangFuncs.find(lang);
    if(i == MapLangFuncs.end())
      throw std::invalid_argument("Language " + lang + " is not defined");

    return i->second(base);
  }
}
