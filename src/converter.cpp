#include "converter.h"

namespace Converter
{
  namespace Constants
  {
    const std::string Space(" ");
    const std::string Hyphen("-");
  }

  std::string Concat(const std::string& str1, const std::string& str2, const std::string& delim)
  {
    return str1 + ((!str1.empty() && !str2.empty()) ? delim : "") + str2;
  }

  unsigned BaseLimits::GetBaseValue(BASE base)
  {
    switch(base)
    {
    case BASE_DECIMAL:
      return 10;
    case BASE_OCTAL:
      return 8;
    default:
      throw std::exception("Wrong BASE value");
    }
  }

}
