#pragma once

#include "numeric.h"
#include <map>
#include <string>

namespace Converter
{
  enum BASE
  {
    BASE_DECIMAL,
    BASE_OCTAL
  };

  namespace Constants
  {
    extern const std::string Space;
    extern const std::string Hyphen;
  }

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
