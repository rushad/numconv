#include "converter.h"
#include "utils.h"

#include "gtest/gtest.h"

namespace Converter
{
  namespace Test
  {
    class TestNumericFactory : public ::testing::Test
    {
    public:
      static Numeric* createInstance(const BASE base)
      {
        return 0;
      }
    };

    class TestUtils : public ::testing::Test
    {
    };

    TEST_F(TestNumericFactory, NullCreateInstanceFuncNotAllowed)
    {
      NumericFactory factory;
      EXPECT_THROW(factory.Add("TEST", 0), std::invalid_argument);
    }

    TEST_F(TestNumericFactory, LanguageRedefenitionNotAllowed)
    {
      NumericFactory factory;
      factory.Add("TEST", createInstance);
      EXPECT_THROW(factory.Add("TEST", createInstance), std::invalid_argument);
    }

    TEST_F(TestNumericFactory, GetWithWrongLangShouldThrowException)
    {
      NumericFactory factory;
      EXPECT_THROW(factory.Get("TEST", BASE_DECIMAL), std::invalid_argument);
    }

    TEST_F(TestUtils, BaseLimitsWithWrongBaseShouldThrowException)
    {
      EXPECT_THROW(Utils::BaseLimits((BASE)123), std::exception);
    }
  }
}