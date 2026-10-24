#include "pch.h"
#include "CppUnitTest.h"
#define LINK_TEST
#include "..\PR6.1it\pr6.1 it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61it
{
	TEST_CLASS(UnitTest61it)
	{
	public:
		
		TEST_METHOD(TestSumIt)
		{
			int test_array[5] = { -5, 2, -10, 3, 4 };
			int actual_sum = Sum(test_array, 5);
			Assert::AreEqual(4, actual_sum);
		}
	};
}
