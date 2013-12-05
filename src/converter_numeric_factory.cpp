#include "converter_numeric_factory.h"

namespace Converter
{
  void NumericFactory::Add(const std::string& lang, CreateInstanceFunc func)
  {
    if(!func)
      throw std::invalid_argument("NULL CreateInstance not allowed");

    std::map<std::string, CreateInstanceFunc>::const_iterator i = MapLangFuncs.find(lang);
    if(i != MapLangFuncs.end())
      throw std::invalid_argument("Language " + lang + " is already defined");

    MapLangFuncs[lang] = func;
  }

  Numeric* NumericFactory::Get(const std::string& lang, BASE base)
  {
    std::map<std::string, CreateInstanceFunc>::const_iterator i = MapLangFuncs.find(lang);
    if(i == MapLangFuncs.end())
      throw std::invalid_argument("Language " + lang + " is not defined");

    return i->second(base);
  }

}