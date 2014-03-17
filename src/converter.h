#pragma once

#include "numeric.h"

#include <map>
#include <memory>
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
  public:
    typedef Numeric::Ptr(*CreateInstanceFunc)(const BASE);

    void Add(const std::string& lang, const CreateInstanceFunc func);
    Numeric::Ptr Get(const std::string& lang, const BASE base);

  private:
    std::map<std::string, CreateInstanceFunc> MapLangFuncs;
  };
}
