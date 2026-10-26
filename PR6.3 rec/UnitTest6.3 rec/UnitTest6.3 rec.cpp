#include "pch.h"
#include "CppUnitTest.h"
#define LINK_TEST
#include "D:\Проєкти VSC++\PR6.3 rec\PR6.3 rec\pr6.3 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63rec
{
	TEST_CLASS(UnitTest63rec)
	{
	public:

		TEST_METHOD(TestDoSwapRec)
		{

			int test_array[5] = { -6, 2, -10, 3, 4 };
			int DoSwapTest = DoSwap(test_array, 5, 1);
			Assert::AreEqual(2, DoSwapTest);
		}
	};
}
