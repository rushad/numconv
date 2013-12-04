#include "numconv.h"
#include "gtest/gtest.h"

namespace Converter
{
  namespace Test
  {
    class ConvTestRu : public ::testing::Test
    {
    };

    TEST_F(ConvTestRu, Zero10)
    {
      std::auto_ptr<NumericConverter> convPtr(RussianNumericConverter::createInstance(BASE_DECIMAL));
      EXPECT_EQ(std::string("����"), convPtr->ToString(0));
    }

    TEST_F(ConvTestRu, Ones10)
    {
      std::auto_ptr<NumericConverter> convPtr(RussianNumericConverter::createInstance(BASE_DECIMAL));
      EXPECT_EQ("����", convPtr->ToString(1));
      EXPECT_EQ("���", convPtr->ToString(2));
      EXPECT_EQ("���", convPtr->ToString(3));
      EXPECT_EQ("������", convPtr->ToString(4));
      EXPECT_EQ("����", convPtr->ToString(5));
      EXPECT_EQ("�����", convPtr->ToString(6));
      EXPECT_EQ("����", convPtr->ToString(7));
      EXPECT_EQ("������", convPtr->ToString(8));
      EXPECT_EQ("������", convPtr->ToString(9));
    }

    TEST_F(ConvTestRu, Teens10)
    {
      std::auto_ptr<NumericConverter> convPtr(RussianNumericConverter::createInstance(BASE_DECIMAL));
      EXPECT_EQ("������", convPtr->ToString(10));
      EXPECT_EQ("�����������", convPtr->ToString(11));
      EXPECT_EQ("����������", convPtr->ToString(12));
      EXPECT_EQ("����������", convPtr->ToString(13));
      EXPECT_EQ("������������", convPtr->ToString(14));
      EXPECT_EQ("����������", convPtr->ToString(15));
      EXPECT_EQ("�����������", convPtr->ToString(16));
      EXPECT_EQ("����������", convPtr->ToString(17));
      EXPECT_EQ("������������", convPtr->ToString(18));
      EXPECT_EQ("������������", convPtr->ToString(19));
    }

    TEST_F(ConvTestRu, TwoDigit10)
    {
      std::auto_ptr<NumericConverter> convPtr(RussianNumericConverter::createInstance(BASE_DECIMAL));
      EXPECT_EQ("��������", convPtr->ToString(20));
      EXPECT_EQ("�������� ����", convPtr->ToString(31));
      EXPECT_EQ("����� ���", convPtr->ToString(42));
      EXPECT_EQ("��������� ���", convPtr->ToString(53));
      EXPECT_EQ("���������� ������", convPtr->ToString(64));
      EXPECT_EQ("��������� ����", convPtr->ToString(75));
      EXPECT_EQ("����������� �����", convPtr->ToString(86));
      EXPECT_EQ("��������� ����", convPtr->ToString(97));
    }

    TEST_F(ConvTestRu, ThreeDigit10)
    {
      std::auto_ptr<NumericConverter> convPtr(RussianNumericConverter::createInstance(BASE_DECIMAL));
      EXPECT_EQ("���", convPtr->ToString(100));
      EXPECT_EQ("��� ����", convPtr->ToString(101));
      EXPECT_EQ("������ ����������", convPtr->ToString(212));
      EXPECT_EQ("������ �������� ���", convPtr->ToString(323));
      EXPECT_EQ("��������� �������� ������", convPtr->ToString(434));
      EXPECT_EQ("������� ����� ����", convPtr->ToString(545));
      EXPECT_EQ("�������� ��������� �����", convPtr->ToString(656));
      EXPECT_EQ("������� ���������� ����", convPtr->ToString(767));
      EXPECT_EQ("��������� ��������� ������", convPtr->ToString(878));
      EXPECT_EQ("��������� ����������� ������", convPtr->ToString(989));
    }

    TEST_F(ConvTestRu, Thousands10)
    {
      std::auto_ptr<NumericConverter> convPtr(RussianNumericConverter::createInstance(BASE_DECIMAL));
      EXPECT_EQ("���� ������", convPtr->ToString(1000));
      EXPECT_EQ("���� ������ ����", convPtr->ToString(1001));
      EXPECT_EQ("������ ����� ����", convPtr->ToString(200001));
      EXPECT_EQ("������ ��� ������ ����", convPtr->ToString(302001));
      EXPECT_EQ("��������� �������� ��� ������ ������� ����", convPtr->ToString(432501));
      EXPECT_EQ("��� �������� ��� ������ ��������� ��������� �����", convPtr->ToString(123456));
      EXPECT_EQ("��� �����", convPtr->ToString(100000));
      EXPECT_EQ("��������� ��������� ������ ����� ��������� ��������� ������", convPtr->ToString(999999));
      EXPECT_EQ("��� ���������� ����� ����", convPtr->ToString(113001));
    }

    TEST_F(ConvTestRu, Millions10)
    {
      std::auto_ptr<NumericConverter> convPtr(RussianNumericConverter::createInstance(BASE_DECIMAL));
      EXPECT_EQ("���� �������", convPtr->ToString(1000000));
      EXPECT_EQ("���� ������� ����", convPtr->ToString(1000001));
      EXPECT_EQ("��� ���������", convPtr->ToString(100 * 1000000));
      EXPECT_EQ("������ ������ ���������", convPtr->ToString(210000000));
      EXPECT_EQ("������ �������� ���� ������� ��� �������� ���", convPtr->ToString(321000123));
      EXPECT_EQ("��� �������� ��� �������� ��������� ��������� ����� ����� ������� ����������� ������", convPtr->ToString(123456789));
      EXPECT_EQ("��� ��� �������� ����� ����� ������", convPtr->ToString(103006009));
      EXPECT_EQ("���������� ��������� �������� ������ ������ ��������� �����", convPtr->ToString(12034056));
      EXPECT_EQ("���� ������� ��� �������� ��� ������ ����", convPtr->ToString(1123001));
      EXPECT_EQ("���� ������� ����������", convPtr->ToString(1000012));
      EXPECT_EQ("���� ������� ���", convPtr->ToString(1000100));
      EXPECT_EQ("���� ������� ��� ����", convPtr->ToString(1000101));
    }

    TEST_F(ConvTestRu, Billions10)
    {
      std::auto_ptr<NumericConverter> convPtr(RussianNumericConverter::createInstance(BASE_DECIMAL));
      EXPECT_EQ("���� ��������", convPtr->ToString(1000000000));
      EXPECT_EQ("���� �������� ����", convPtr->ToString(1000000001));
      EXPECT_EQ("���� �������� ����������", convPtr->ToString(1000000012));
      EXPECT_EQ("���� �������� ��� ����", convPtr->ToString(1000000101));
      EXPECT_EQ("���� �������� ��� �������� ��� ������ ����", convPtr->ToString(1000123001));
      EXPECT_EQ("���� �������� ��� �������� ��� �������� ����", convPtr->ToString(1123000001));
      EXPECT_EQ("���� �������� �������� ��� �������� ����", convPtr->ToString(1023000001));
      EXPECT_EQ("���� �������� �������� ��� ������ ����", convPtr->ToString(1000023001));
    }

    TEST_F(ConvTestRu, Zero8)
    {
      std::auto_ptr<NumericConverter> convPtr(RussianNumericConverter::createInstance(BASE_OCTAL));
      EXPECT_EQ(std::string("����"), convPtr->ToString(00));
    }

    TEST_F(ConvTestRu, Ones8)
    {
      std::auto_ptr<NumericConverter> convPtr(RussianNumericConverter::createInstance(BASE_OCTAL));
      EXPECT_EQ("����", convPtr->ToString(01));
      EXPECT_EQ("���", convPtr->ToString(02));
      EXPECT_EQ("���", convPtr->ToString(03));
      EXPECT_EQ("������", convPtr->ToString(04));
      EXPECT_EQ("����", convPtr->ToString(05));
      EXPECT_EQ("�����", convPtr->ToString(06));
      EXPECT_EQ("����", convPtr->ToString(07));
    }

    TEST_F(ConvTestRu, Teens8)
    {
      std::auto_ptr<NumericConverter> convPtr(RussianNumericConverter::createInstance(BASE_OCTAL));
      EXPECT_EQ("������", convPtr->ToString(010));
      EXPECT_EQ("�����������", convPtr->ToString(011));
      EXPECT_EQ("����������", convPtr->ToString(012));
      EXPECT_EQ("����������", convPtr->ToString(013));
      EXPECT_EQ("������������", convPtr->ToString(014));
      EXPECT_EQ("����������", convPtr->ToString(015));
      EXPECT_EQ("�����������", convPtr->ToString(016));
      EXPECT_EQ("����������", convPtr->ToString(017));
    }

    TEST_F(ConvTestRu, TwoDigit8)
    {
      std::auto_ptr<NumericConverter> convPtr(RussianNumericConverter::createInstance(BASE_OCTAL));
      EXPECT_EQ("��������", convPtr->ToString(020));
      EXPECT_EQ("�������� ����", convPtr->ToString(031));
      EXPECT_EQ("����� ���", convPtr->ToString(042));
      EXPECT_EQ("��������� ���", convPtr->ToString(053));
      EXPECT_EQ("���������� ������", convPtr->ToString(064));
      EXPECT_EQ("��������� ����", convPtr->ToString(075));
    }

    TEST_F(ConvTestRu, ThreeDigit8)
    {
      std::auto_ptr<NumericConverter> convPtr(RussianNumericConverter::createInstance(BASE_OCTAL));
      EXPECT_EQ("���", convPtr->ToString(0100));
      EXPECT_EQ("��� ����", convPtr->ToString(0101));
      EXPECT_EQ("������ ����������", convPtr->ToString(0212));
      EXPECT_EQ("������ �������� ���", convPtr->ToString(0323));
      EXPECT_EQ("��������� �������� ������", convPtr->ToString(0434));
      EXPECT_EQ("������� ����� ����", convPtr->ToString(0545));
      EXPECT_EQ("�������� ��������� �����", convPtr->ToString(0656));
      EXPECT_EQ("������� ���������� ����", convPtr->ToString(0767));
    }

    TEST_F(ConvTestRu, Thousands8)
    {
      std::auto_ptr<NumericConverter> convPtr(RussianNumericConverter::createInstance(BASE_OCTAL));
      EXPECT_EQ("���� ������", convPtr->ToString(01000));
      EXPECT_EQ("���� ������ ����", convPtr->ToString(01001));
      EXPECT_EQ("������ ����� ����", convPtr->ToString(0200001));
      EXPECT_EQ("������ ��� ������ ����", convPtr->ToString(0302001));
      EXPECT_EQ("��������� �������� ��� ������ ������� ����", convPtr->ToString(0432501));
      EXPECT_EQ("��� �������� ��� ������ ��������� ��������� �����", convPtr->ToString(0123456));
      EXPECT_EQ("��� �����", convPtr->ToString(0100000));
      EXPECT_EQ("������� ��������� ���� ����� ������� ��������� ����", convPtr->ToString(0777777));
      EXPECT_EQ("��� ���������� ����� ����", convPtr->ToString(0113001));
    }

    TEST_F(ConvTestRu, Millions8)
    {
      std::auto_ptr<NumericConverter> convPtr(RussianNumericConverter::createInstance(BASE_OCTAL));
      EXPECT_EQ("���� �������", convPtr->ToString(01000000));
      EXPECT_EQ("���� ������� ����", convPtr->ToString(01000001));
      EXPECT_EQ("��� ���������", convPtr->ToString(0100 * 01000000));
      EXPECT_EQ("������ ������ ���������", convPtr->ToString(0210000000));
      EXPECT_EQ("������ �������� ���� ������� ��� �������� ���", convPtr->ToString(0321000123));
      EXPECT_EQ("��� �������� ��� �������� ��������� ��������� ����� ����� ������� ���������� ����", convPtr->ToString(0123456765));
      EXPECT_EQ("��� ��� �������� ����� ����� ����", convPtr->ToString(0103006007));
      EXPECT_EQ("���������� ��������� �������� ������ ������ ��������� �����", convPtr->ToString(012034056));
      EXPECT_EQ("���� ������� ��� �������� ��� ������ ����", convPtr->ToString(01123001));
      EXPECT_EQ("���� ������� ����������", convPtr->ToString(01000012));
      EXPECT_EQ("���� ������� ���", convPtr->ToString(01000100));
      EXPECT_EQ("���� ������� ��� ����", convPtr->ToString(01000101));
    }

    TEST_F(ConvTestRu, Billions8)
    {
      std::auto_ptr<NumericConverter> convPtr(RussianNumericConverter::createInstance(BASE_OCTAL));
      EXPECT_EQ("���� ��������", convPtr->ToString(01000000000));
      EXPECT_EQ("���� �������� ����", convPtr->ToString(01000000001));
      EXPECT_EQ("���� �������� ����������", convPtr->ToString(01000000012));
      EXPECT_EQ("���� �������� ��� ����", convPtr->ToString(01000000101));
      EXPECT_EQ("���� �������� ��� �������� ��� ������ ����", convPtr->ToString(01000123001));
      EXPECT_EQ("���� �������� ��� �������� ��� �������� ����", convPtr->ToString(01123000001));
      EXPECT_EQ("���� �������� �������� ��� �������� ����", convPtr->ToString(01023000001));
      EXPECT_EQ("���� �������� �������� ��� ������ ����", convPtr->ToString(01000023001));
    }
  }
}