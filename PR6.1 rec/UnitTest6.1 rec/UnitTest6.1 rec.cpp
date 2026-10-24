#include "pch.h"
#include "CppUnitTest.h"
#define LINK_TEST
#include "../PR6.1 rec/pr6.1 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61rec
{
	TEST_CLASS(UnitTest61rec)
	{
	public:
		
		TEST_METHOD(TestSumRec)
		{
			
			int test_array[6] = { -2, -7, 5, 0, -4, 9 };
			int actual_sum = Sum(test_array, 6, 0);
			Assert::AreEqual(7, actual_sum);
		}
	};
}
