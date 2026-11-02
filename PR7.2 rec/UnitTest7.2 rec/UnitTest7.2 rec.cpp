#include "pch.h"
#include "CppUnitTest.h"
#define LINK_TEST
#include "D:\Проєкти VSC++\PR7.2 rec\PR7.2 rec\pr7.2 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72rec
{
	TEST_CLASS(UnitTest72rec)
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
