#include "russian_numeric_converter.h"
#include "gtest/gtest.h"

namespace Converter
{
  namespace Test
  {
    class ConvTestRu : public ::testing::Test
    {
    public:
      ConvTestRu()
        : pConv10(RussianNumericConverter::CreateInstance(BASE_DECIMAL))
        , pConv8(RussianNumericConverter::CreateInstance(BASE_OCTAL))
      {
      }

    protected:
      std::auto_ptr<NumericConverter> pConv10;
      std::auto_ptr<NumericConverter> pConv8;
    };

    TEST_F(ConvTestRu, Zero10)
    {
      EXPECT_EQ(std::string("����"), pConv10->ToString(0));
    }

    TEST_F(ConvTestRu, Ones10)
    {
      EXPECT_EQ("����", pConv10->ToString(1));
      EXPECT_EQ("���", pConv10->ToString(2));
      EXPECT_EQ("���", pConv10->ToString(3));
      EXPECT_EQ("������", pConv10->ToString(4));
      EXPECT_EQ("����", pConv10->ToString(5));
      EXPECT_EQ("�����", pConv10->ToString(6));
      EXPECT_EQ("����", pConv10->ToString(7));
      EXPECT_EQ("������", pConv10->ToString(8));
      EXPECT_EQ("������", pConv10->ToString(9));
    }

    TEST_F(ConvTestRu, Teens10)
    {
      EXPECT_EQ("������", pConv10->ToString(10));
      EXPECT_EQ("�����������", pConv10->ToString(11));
      EXPECT_EQ("����������", pConv10->ToString(12));
      EXPECT_EQ("����������", pConv10->ToString(13));
      EXPECT_EQ("������������", pConv10->ToString(14));
      EXPECT_EQ("����������", pConv10->ToString(15));
      EXPECT_EQ("�����������", pConv10->ToString(16));
      EXPECT_EQ("����������", pConv10->ToString(17));
      EXPECT_EQ("������������", pConv10->ToString(18));
      EXPECT_EQ("������������", pConv10->ToString(19));
    }

    TEST_F(ConvTestRu, TwoDigit10)
    {
      EXPECT_EQ("��������", pConv10->ToString(20));
      EXPECT_EQ("�������� ����", pConv10->ToString(31));
      EXPECT_EQ("����� ���", pConv10->ToString(42));
      EXPECT_EQ("��������� ���", pConv10->ToString(53));
      EXPECT_EQ("���������� ������", pConv10->ToString(64));
      EXPECT_EQ("��������� ����", pConv10->ToString(75));
      EXPECT_EQ("����������� �����", pConv10->ToString(86));
      EXPECT_EQ("��������� ����", pConv10->ToString(97));
    }

    TEST_F(ConvTestRu, ThreeDigit10)
    {
      EXPECT_EQ("���", pConv10->ToString(100));
      EXPECT_EQ("��� ����", pConv10->ToString(101));
      EXPECT_EQ("������ ����������", pConv10->ToString(212));
      EXPECT_EQ("������ �������� ���", pConv10->ToString(323));
      EXPECT_EQ("��������� �������� ������", pConv10->ToString(434));
      EXPECT_EQ("������� ����� ����", pConv10->ToString(545));
      EXPECT_EQ("�������� ��������� �����", pConv10->ToString(656));
      EXPECT_EQ("������� ���������� ����", pConv10->ToString(767));
      EXPECT_EQ("��������� ��������� ������", pConv10->ToString(878));
      EXPECT_EQ("��������� ����������� ������", pConv10->ToString(989));
    }

    TEST_F(ConvTestRu, Thousands10)
    {
      EXPECT_EQ("���� ������", pConv10->ToString(1000));
      EXPECT_EQ("���� ������ ����", pConv10->ToString(1001));
      EXPECT_EQ("������ ����� ����", pConv10->ToString(200001));
      EXPECT_EQ("������ ��� ������ ����", pConv10->ToString(302001));
      EXPECT_EQ("��������� �������� ��� ������ ������� ����", pConv10->ToString(432501));
      EXPECT_EQ("��� �������� ��� ������ ��������� ��������� �����", pConv10->ToString(123456));
      EXPECT_EQ("��� �����", pConv10->ToString(100000));
      EXPECT_EQ("��������� ��������� ������ ����� ��������� ��������� ������", pConv10->ToString(999999));
      EXPECT_EQ("��� ���������� ����� ����", pConv10->ToString(113001));
    }

    TEST_F(ConvTestRu, Millions10)
    {
      EXPECT_EQ("���� �������", pConv10->ToString(1000000));
      EXPECT_EQ("���� ������� ����", pConv10->ToString(1000001));
      EXPECT_EQ("��� ���������", pConv10->ToString(100 * 1000000));
      EXPECT_EQ("������ ������ ���������", pConv10->ToString(210000000));
      EXPECT_EQ("������ �������� ���� ������� ��� �������� ���", pConv10->ToString(321000123));
      EXPECT_EQ("��� �������� ��� �������� ��������� ��������� ����� ����� ������� ����������� ������", pConv10->ToString(123456789));
      EXPECT_EQ("��� ��� �������� ����� ����� ������", pConv10->ToString(103006009));
      EXPECT_EQ("���������� ��������� �������� ������ ������ ��������� �����", pConv10->ToString(12034056));
      EXPECT_EQ("���� ������� ��� �������� ��� ������ ����", pConv10->ToString(1123001));
      EXPECT_EQ("���� ������� ����������", pConv10->ToString(1000012));
      EXPECT_EQ("���� ������� ���", pConv10->ToString(1000100));
      EXPECT_EQ("���� ������� ��� ����", pConv10->ToString(1000101));
    }

    TEST_F(ConvTestRu, Billions10)
    {
      EXPECT_EQ("���� ��������", pConv10->ToString(1000000000));
      EXPECT_EQ("���� �������� ����", pConv10->ToString(1000000001));
      EXPECT_EQ("���� �������� ����������", pConv10->ToString(1000000012));
      EXPECT_EQ("���� �������� ��� ����", pConv10->ToString(1000000101));
      EXPECT_EQ("���� �������� ��� �������� ��� ������ ����", pConv10->ToString(1000123001));
      EXPECT_EQ("���� �������� ��� �������� ��� �������� ����", pConv10->ToString(1123000001));
      EXPECT_EQ("���� �������� �������� ��� �������� ����", pConv10->ToString(1023000001));
      EXPECT_EQ("���� �������� �������� ��� ������ ����", pConv10->ToString(1000023001));
    }

    TEST_F(ConvTestRu, Zero8)
    {
      EXPECT_EQ(std::string("����"), pConv8->ToString(00));
    }

    TEST_F(ConvTestRu, Ones8)
    {
      EXPECT_EQ("����", pConv8->ToString(01));
      EXPECT_EQ("���", pConv8->ToString(02));
      EXPECT_EQ("���", pConv8->ToString(03));
      EXPECT_EQ("������", pConv8->ToString(04));
      EXPECT_EQ("����", pConv8->ToString(05));
      EXPECT_EQ("�����", pConv8->ToString(06));
      EXPECT_EQ("����", pConv8->ToString(07));
    }

    TEST_F(ConvTestRu, Teens8)
    {
      EXPECT_EQ("������", pConv8->ToString(010));
      EXPECT_EQ("�����������", pConv8->ToString(011));
      EXPECT_EQ("����������", pConv8->ToString(012));
      EXPECT_EQ("����������", pConv8->ToString(013));
      EXPECT_EQ("������������", pConv8->ToString(014));
      EXPECT_EQ("����������", pConv8->ToString(015));
      EXPECT_EQ("�����������", pConv8->ToString(016));
      EXPECT_EQ("����������", pConv8->ToString(017));
    }

    TEST_F(ConvTestRu, TwoDigit8)
    {
      EXPECT_EQ("��������", pConv8->ToString(020));
      EXPECT_EQ("�������� ����", pConv8->ToString(031));
      EXPECT_EQ("����� ���", pConv8->ToString(042));
      EXPECT_EQ("��������� ���", pConv8->ToString(053));
      EXPECT_EQ("���������� ������", pConv8->ToString(064));
      EXPECT_EQ("��������� ����", pConv8->ToString(075));
    }

    TEST_F(ConvTestRu, ThreeDigit8)
    {
      EXPECT_EQ("���", pConv8->ToString(0100));
      EXPECT_EQ("��� ����", pConv8->ToString(0101));
      EXPECT_EQ("������ ����������", pConv8->ToString(0212));
      EXPECT_EQ("������ �������� ���", pConv8->ToString(0323));
      EXPECT_EQ("��������� �������� ������", pConv8->ToString(0434));
      EXPECT_EQ("������� ����� ����", pConv8->ToString(0545));
      EXPECT_EQ("�������� ��������� �����", pConv8->ToString(0656));
      EXPECT_EQ("������� ���������� ����", pConv8->ToString(0767));
    }

    TEST_F(ConvTestRu, Thousands8)
    {
      EXPECT_EQ("���� ������", pConv8->ToString(01000));
      EXPECT_EQ("���� ������ ����", pConv8->ToString(01001));
      EXPECT_EQ("������ ����� ����", pConv8->ToString(0200001));
      EXPECT_EQ("������ ��� ������ ����", pConv8->ToString(0302001));
      EXPECT_EQ("��������� �������� ��� ������ ������� ����", pConv8->ToString(0432501));
      EXPECT_EQ("��� �������� ��� ������ ��������� ��������� �����", pConv8->ToString(0123456));
      EXPECT_EQ("��� �����", pConv8->ToString(0100000));
      EXPECT_EQ("������� ��������� ���� ����� ������� ��������� ����", pConv8->ToString(0777777));
      EXPECT_EQ("��� ���������� ����� ����", pConv8->ToString(0113001));
    }

    TEST_F(ConvTestRu, Millions8)
    {
      EXPECT_EQ("���� �������", pConv8->ToString(01000000));
      EXPECT_EQ("���� ������� ����", pConv8->ToString(01000001));
      EXPECT_EQ("��� ���������", pConv8->ToString(0100 * 01000000));
      EXPECT_EQ("������ ������ ���������", pConv8->ToString(0210000000));
      EXPECT_EQ("������ �������� ���� ������� ��� �������� ���", pConv8->ToString(0321000123));
      EXPECT_EQ("��� �������� ��� �������� ��������� ��������� ����� ����� ������� ���������� ����", pConv8->ToString(0123456765));
      EXPECT_EQ("��� ��� �������� ����� ����� ����", pConv8->ToString(0103006007));
      EXPECT_EQ("���������� ��������� �������� ������ ������ ��������� �����", pConv8->ToString(012034056));
      EXPECT_EQ("���� ������� ��� �������� ��� ������ ����", pConv8->ToString(01123001));
      EXPECT_EQ("���� ������� ����������", pConv8->ToString(01000012));
      EXPECT_EQ("���� ������� ���", pConv8->ToString(01000100));
      EXPECT_EQ("���� ������� ��� ����", pConv8->ToString(01000101));
    }

    TEST_F(ConvTestRu, Billions8)
    {
      EXPECT_EQ("���� ��������", pConv8->ToString(01000000000));
      EXPECT_EQ("���� �������� ����", pConv8->ToString(01000000001));
      EXPECT_EQ("���� �������� ����������", pConv8->ToString(01000000012));
      EXPECT_EQ("���� �������� ��� ����", pConv8->ToString(01000000101));
      EXPECT_EQ("���� �������� ��� �������� ��� ������ ����", pConv8->ToString(01000123001));
      EXPECT_EQ("���� �������� ��� �������� ��� �������� ����", pConv8->ToString(01123000001));
      EXPECT_EQ("���� �������� �������� ��� �������� ����", pConv8->ToString(01023000001));
      EXPECT_EQ("���� �������� �������� ��� ������ ����", pConv8->ToString(01000023001));
    }
  }
}