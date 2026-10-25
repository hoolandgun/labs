#include "pch.h"
#include "CppUnitTest.h"
#define LINK_TEST
#include "..\RR6.2 it\pr6.2 it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62it
{
	TEST_CLASS(UnitTest62it)
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
