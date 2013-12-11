#pragma once

#include "numeric.h"

#include <map>
#include <memory>
#include <string>

namespace Converter
{
  typedef std::auto_ptr<Numeric> NumericPtr;

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
    typedef NumericPtr(*CreateInstanceFunc)(const BASE);

    void Add(const std::string& lang, const CreateInstanceFunc func);
    NumericPtr Get(const std::string& lang, const BASE base);

  private:
    std::map<std::string, CreateInstanceFunc> MapLangFuncs;
  };
}
