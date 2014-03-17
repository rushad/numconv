#pragma once

#include <memory>
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

    typedef std::auto_ptr<Numeric> Ptr;
  };
}