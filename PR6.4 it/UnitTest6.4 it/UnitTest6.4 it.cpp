#include "pch.h"
#include "CppUnitTest.h"
#define LINK_TEST
#include "D:\Проєкти VSC++\PR6.4 it\PR6.4 it\pr6.4 it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64it
{
	TEST_CLASS(UnitTest64it)
	{
	public:

		TEST_METHOD(TestFindMinIt)
		{

			double test_array[5] = { -6.2, 2.4, -10.7, 3.6, 4.5 };
			int FindMinTest = FindMin(test_array, 5);
			Assert::AreEqual(1, FindMinTest);
		}
	};
}