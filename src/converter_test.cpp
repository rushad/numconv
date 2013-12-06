#include "converter.h"
#include "utils.h"

#include "gtest/gtest.h"

namespace Converter
{
  namespace Test
  {
    class ConverterNumericFactoryTest : public ::testing::Test
    {
    public:
      static Numeric* createInstance(const BASE base)
      {
        return 0;
      }
    };

    TEST_F(ConverterNumericFactoryTest, NullCreateInstanceFuncNotAllowed)
    {
      NumericFactory factory;
      EXPECT_THROW(factory.Add("TEST", 0), std::invalid_argument);
    }

    TEST_F(ConverterNumericFactoryTest, LanguageRedefenitionNotAllowed)
    {
      NumericFactory factory;
      factory.Add("TEST", createInstance);
      EXPECT_THROW(factory.Add("TEST", createInstance), std::invalid_argument);
    }

    TEST_F(ConverterNumericFactoryTest, GetWithWrongLangShouldThrowException)
    {
      NumericFactory factory;
      EXPECT_THROW(factory.Get("TEST", BASE_DECIMAL), std::invalid_argument);
    }

    TEST_F(ConverterNumericFactoryTest, BaseLimitsTest)
    {
      EXPECT_THROW(Utils::BaseLimits((BASE)123), std::exception);
    }
  }
}