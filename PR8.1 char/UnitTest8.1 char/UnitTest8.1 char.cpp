#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#define LINK_TEST
#include "D:\Проєкти VSC++\PR8.1 char\PR8.1 char\pr8.1 char.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81char
{
	TEST_CLASS(UnitTest81char)
	{
	public:

		TEST_METHOD(TestCount)
		{
			char str[] = "TESTOGOTESTAGATEST";
			Assert::AreEqual(2, Count(str));
		}
	};
}