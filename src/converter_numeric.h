#pragma once

#include <string>

namespace Converter
{
  class Numeric
  {
  public:
    virtual ~Numeric()
    {
    }

    virtual std::string ToString(const unsigned num) const = 0;
  };
}