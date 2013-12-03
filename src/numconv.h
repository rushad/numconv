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

  enum LANG
  {
    LANG_ENGLISH,
    LANG_RUSSIAN
  };

  enum BASE
  {
    BASE_DECIMAL,
    BASE_OCTAL,
  };

  class NumericConverter
  {
  public:
    explicit NumericConverter(const BASE base);
    std::string ToString(const unsigned num) const;

  protected:
    virtual std::string ConvertToString(const unsigned num) const = 0;

  protected:
    const unsigned Base;
    const unsigned BaseTwenty;
    const unsigned BaseHundred;
    const unsigned BaseThousand;
  };

  class NumericConverterFactory
  {
    typedef NumericConverter*(*CreateInstanceFunc)(const BASE);

  public:
    void Add(const LANG lang, CreateInstanceFunc func);
    NumericConverter* Get(LANG lang, BASE base);

  private:
    std::map<LANG, CreateInstanceFunc> MapLangFuncs;
  };

  class EnglishNumericConverter : public NumericConverter
  {
  public:
    static NumericConverter* createInstance(const BASE base);

  private:
    explicit EnglishNumericConverter(const BASE base);
  
  protected:
    virtual std::string ConvertToString(const unsigned num) const;

  private:
    bool InRange1To99(const unsigned num) const;
    unsigned GroupUnit(const unsigned group) const;
    std::string ConvertGroup(const unsigned num, const unsigned group) const;
    std::string Convert(const unsigned num, const bool skipZero) const;
  };

  class RussianNumericConverter : public NumericConverter
  {
  public:
    static NumericConverter* createInstance(const BASE base);

  private:
    explicit RussianNumericConverter(const BASE base);
  
  protected:
    virtual std::string ConvertToString(const unsigned num) const;

  private:
    std::string PluralForm(const unsigned num, const char** forms) const;
    std::string Convert(const unsigned num, const bool skipZero, const bool feminine) const;
  };

}
#endif // NUMCONV_H
