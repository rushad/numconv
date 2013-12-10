#include "converter.h"

namespace Converter
{
  namespace Constants
  {
    const std::string Space(" ");
    const std::string Hyphen("-");
  }

  void NumericFactory::Add(const std::string& lang, CreateInstanceFunc func)
  {
    if(!func)
      throw std::invalid_argument("NULL CreateInstance not allowed");

    std::map<std::string, CreateInstanceFunc>::const_iterator i = MapLangFuncs.find(lang);
    if(i != MapLangFuncs.end())
      throw std::invalid_argument("Language " + lang + " is already defined");

    MapLangFuncs[lang] = func;
  }

  NumericPtr NumericFactory::Get(const std::string& lang, BASE base)
  {
    std::map<std::string, CreateInstanceFunc>::const_iterator i = MapLangFuncs.find(lang);
    if(i == MapLangFuncs.end())
      throw std::invalid_argument("Language " + lang + " is not defined");

    return i->second(base);
  }
}
