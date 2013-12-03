#include "numconv.h"

#include <gtest/gtest.h>

#include <boost/lexical_cast.hpp>
#include <iostream>

bool Str2Uint(const std::string& origStr, unsigned& num)
{
  unsigned tempNum;
  try
  {
    tempNum = boost::lexical_cast<unsigned>(origStr);
    std::string str = boost::lexical_cast<std::string>(tempNum);
    num = tempNum;
    return str == origStr;
  }
  catch(const boost::bad_lexical_cast &)
  {
  }
  return false;
}

bool CheckOptions(int argc, char** argv, Converter::LANG* ptrLang, Converter::BASE* ptrBase)
{
  bool langWasSet = false;
  bool baseWasSet = false;
  Converter::LANG lang = Converter::LANG_ENGLISH;
  Converter::BASE base = Converter::BASE_DECIMAL;

  for (int i = 1; i < argc; ++i)
  {
    std::string opt(argv[i]);
    if(opt == "--gtest")
    {
      std::cout << "Running tests..." << std::endl;
      testing::InitGoogleTest(&argc, argv);
      RUN_ALL_TESTS();
      return false;
    }
    else if(!langWasSet && (opt == "--en"))
    {
      langWasSet = true;
      lang = Converter::LANG_ENGLISH;
    }
    else if(!langWasSet && (opt == "--ru"))
    {
      langWasSet = true;
      lang = Converter::LANG_RUSSIAN;
    }
    else if(!baseWasSet && (opt == "--dec"))
    {
      baseWasSet = true;
      base = Converter::BASE_DECIMAL;
    }
    else if(!baseWasSet && (opt == "--oct"))
    {
      baseWasSet = true;
      base = Converter::BASE_OCTAL;
    }
    else
    {
      std::cout << "Converts unsigned int values to numeral string." << std::endl;
      std::cout << "Usage:" << std::endl;
      std::cout << "  numconv [--gtest] [--en|--ru] [--dec|--oct]" << std::endl;
      std::cout << "Press Ctrl-Z, Enter to exit." << std::endl;
      return false;
    }
  }

  *ptrLang = lang;
  *ptrBase = base;
  return true;
}

GTEST_API_ int main(int argc, char** argv) 
{
  setlocale(LC_ALL, "RUS");

  Converter::LANG lang = Converter::LANG_ENGLISH;
  Converter::BASE base = Converter::BASE_DECIMAL;

  if(!CheckOptions(argc, argv, &lang, &base))
  {
    return -1;
  }

  Converter::NumericConverterFactory factory;
  factory.Add(Converter::LANG_ENGLISH, Converter::EnglishNumericConverter::createInstance);
  factory.Add(Converter::LANG_RUSSIAN, Converter::RussianNumericConverter::createInstance);

  std::auto_ptr<Converter::NumericConverter> convPtr(factory.Get(lang, base));

  unsigned number;
  std::string numbuf;

  while (!(std::cin >> numbuf).eof())
  {
    if(!Str2Uint(numbuf, number))
    {
      std::cerr << "Wrong UINT number entered" << std::endl;
      continue;
    }

    std::cout << convPtr->ToString(number) << std::endl;
  }
  return 0;
}
