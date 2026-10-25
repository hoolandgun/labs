#include "pch.h"
#include "CppUnitTest.h"
#define LINK_TEST
#include "D:\Проєкти VSC++\PR6.2 rec\PR6.2 rec\pr6.2 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62rec
{
	TEST_CLASS(UnitTest62rec)
	{
	public:

		TEST_METHOD(TestSwapIt)
		{

			int test_array[5] = { -6, 2, -10, 3, 4 };
			int FirstTest = First(test_array, 5);
			Assert::AreEqual(3, FirstTest);
		}
	};
}