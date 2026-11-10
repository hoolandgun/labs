#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#define LINK_TEST
#include "D:\Проєкти VSC++\PR8.1 str\PR8.1 str\pr8.1 str.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81str
{
	TEST_CLASS(UnitTest81str)
	{
	public:

		TEST_METHOD(TestCount)
		{
			char str[] = "TESTOGOTESTAGATEST";
			Assert::AreEqual(2, Count(str));
		}
	};
}