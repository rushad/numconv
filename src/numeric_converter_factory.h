#pragma once

#include "numeric_converter.h"

#include <map>

namespace Converter
{
  enum BASE
  {
    BASE_DECIMAL,
    BASE_OCTAL
  };

  class NumericConverterFactory
  {
    typedef NumericConverter*(*CreateInstanceFunc)(const BASE);

  public:
    void Add(const std::string& lang, const CreateInstanceFunc func);
    NumericConverter* Get(const std::string& lang, const BASE base);

  private:
    std::map<std::string, CreateInstanceFunc> MapLangFuncs;
  };

}