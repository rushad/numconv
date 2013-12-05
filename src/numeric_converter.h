#pragma once

#include <string>

namespace Converter
{
  class NumericConverter
  {
  public:
    virtual ~NumericConverter()
    {
    }

    virtual std::string ToString(const unsigned num) const = 0;
  };
}