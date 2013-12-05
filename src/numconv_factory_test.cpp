#include "numeric_converter_factory.h"
#include "converter_utils.h"

#include "gtest/gtest.h"

namespace Converter
{
  namespace Test
  {
    class NumericConverterFactoryTest : public ::testing::Test
    {
    public:
      static NumericConverter* createInstance(const BASE base)
      {
        return 0;
      }
    };

    TEST_F(NumericConverterFactoryTest, NullCreateInstanceFuncNotAllowed)
    {
      NumericConverterFactory factory;
      EXPECT_THROW(factory.Add("TEST", 0), std::invalid_argument);
    }

    TEST_F(NumericConverterFactoryTest, LanguageRedefenitionNotAllowed)
    {
      NumericConverterFactory factory;
      factory.Add("TEST", createInstance);
      EXPECT_THROW(factory.Add("TEST", createInstance), std::invalid_argument);
    }

    TEST_F(NumericConverterFactoryTest, GetWithWrongLangShouldThrowException)
    {
      NumericConverterFactory factory;
      EXPECT_THROW(factory.Get("TEST", BASE_DECIMAL), std::invalid_argument);
    }

    TEST_F(NumericConverterFactoryTest, BaseLimitsTest)
    {
      EXPECT_THROW(BaseLimits((BASE)123), std::exception);
    }
  }
}