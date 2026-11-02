#include "pch.h"
#include "CppUnitTest.h"
#define LINK_TEST
#include "D:\Проєкти VSC++\PR7.2 it\PR7.2 it\pr7.2 it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72it
{
	TEST_CLASS(UnitTest72it)
	{
	public:
		
		TEST_METHOD(TestSumOfMins)
		{
			int m0 = 10;
			int m2 = 15;
			int m4 = 8;
			int m6 = 22;

			int actualSum = SumOfMins(m0, m2, m4, m6);

			Assert::AreEqual(55, actualSum);
		}
	};
}
