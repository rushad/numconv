#include "converter.h"
#include "utils.h"

#include "gtest/gtest.h"

namespace Converter
{
  namespace Test
  {
    class NumericFake : public Numeric
    {
    public:
      virtual std::string ToString(const unsigned num) const
      {
        return "";
      }
    };
    class TestNumericFactory : public ::testing::Test
    {
    public:
      static Numeric::Ptr createInstance(const BASE base)
      {
        return Numeric::Ptr(new NumericFake());
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

    TEST_F(TestNumericFactory, GetShouldReturnValidNumericObject)
    {
      NumericFactory factory;
      factory.Add("TEST", createInstance);
      Numeric::Ptr numeric = factory.Get("TEST", BASE_DECIMAL);
      EXPECT_NE(static_cast<Numeric*>(0), numeric.get());
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