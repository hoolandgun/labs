#include "pch.h"
#include "CppUnitTest.h"
#define LINK_TEST
#include "D:\Проєкти VSC++\PR6.3  it\PR6.3  it\pr6.3 it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63rec
{
	TEST_CLASS(UnitTest63It)
	{
	public:

		TEST_METHOD(TestDoSwapIt)
		{

			int test_array[5] = { -6, 2, -10, 3, 4 };
			int DoSwapTest = DoSwap(test_array, 5, 0, 5);
			Assert::AreEqual(2, DoSwapTest);
		}
	};
}