#ifndef NUMCONV_H
#define NUMCONV_H

#include <string>
#include <map>

namespace Converter
{
  namespace Constants
  {
    extern const std::string Space;
    extern const std::string Hyphen;
  }

  std::string Concat(const std::string& str1, const std::string& str2, const std::string& delim);

  enum BASE
  {
    BASE_DECIMAL,
    BASE_OCTAL,
  };

  class NumericConverter
  {
  public:
    virtual ~NumericConverter()
    {
    }

    virtual std::string ToString(const unsigned num) const = 0;
  };

  class BaseLimits
  {
  public:
    BaseLimits(BASE base)
    {
      switch(base)
      {
      case BASE_DECIMAL:
        BaseValue = 10;
        break;
      case BASE_OCTAL:
        BaseValue = 8;
        break;
      }
    }
    unsigned Base() const
    {
      return BaseValue;
    }
    unsigned BaseTwenty() const
    {
      return 2 * BaseValue;
    }
    unsigned BaseHundred() const
    {
      return BaseValue * BaseValue;
    }
    unsigned BaseThousand() const
    {
      return BaseValue * BaseValue * BaseValue;
    }
  private:
    unsigned BaseValue;
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

  class EnglishNumericConverter : public NumericConverter
  {
  public:
    static NumericConverter* createInstance(const BASE base);

    virtual std::string ToString(const unsigned num) const;

  private:
    explicit EnglishNumericConverter(const BASE base);
  
    bool InRange1To99(const unsigned num) const;
    unsigned GroupUnit(const unsigned group) const;
    std::string ConvertGroup(const unsigned num, const unsigned group) const;
    std::string Convert(const unsigned num, const bool skipZero) const;

    BaseLimits Limits;
  };

  class RussianNumericConverter : public NumericConverter
  {
  public:
    static NumericConverter* createInstance(const BASE base);

    virtual std::string ToString(const unsigned num) const;

  private:
    explicit RussianNumericConverter(const BASE base);
  
    std::string PluralForm(const unsigned num, const char** forms) const;
    std::string Convert(const unsigned num, const bool skipZero, const bool feminine) const;

    BaseLimits Limits;
  };

}
#endif // NUMCONV_H
