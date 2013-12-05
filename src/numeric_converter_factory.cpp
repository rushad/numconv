#include "numeric_converter_factory.h"

namespace Converter
{
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