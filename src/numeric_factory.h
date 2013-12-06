#pragma once

#include "converter.h"
#include "numeric.h"

#include <map>

namespace Converter
{
  class NumericFactory
  {
    typedef Numeric*(*CreateInstanceFunc)(const BASE);

  public:
    void Add(const std::string& lang, const CreateInstanceFunc func);
    Numeric* Get(const std::string& lang, const BASE base);

  private:
    std::map<std::string, CreateInstanceFunc> MapLangFuncs;
  };

}