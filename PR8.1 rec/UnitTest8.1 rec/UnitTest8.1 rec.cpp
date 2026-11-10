#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#define LINK_TEST
#include "D:\Проєкти VSC++\PR8.1 rec\PR8.1 rec\pr8.1 rec.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81rec
{
	TEST_CLASS(UnitTest81rec)
	{
	public:

		TEST_METHOD(TestCount)
		{
			char str[] = "TESTOGOTESTAGATEST";
			Assert::AreEqual(2, Count(str, 0));
		}
	};
}
