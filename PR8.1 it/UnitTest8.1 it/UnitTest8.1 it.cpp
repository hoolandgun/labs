#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#define LINK_TEST
#include "D:\Проєкти VSC++\PR8.1 it\PR8.1 it\pr8.1 it.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81it
{
	TEST_CLASS(UnitTest81it)
	{
	public:
		
		TEST_METHOD(TestCount)
		{
			char str[] = "TESTOGOTESTAGATEST";
			Assert::AreEqual(2, Count(str));
		}
	};
}
