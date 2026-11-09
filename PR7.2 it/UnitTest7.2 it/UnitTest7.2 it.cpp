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
		
		TEST_METHOD(TestFindAndSumMins)
		{
			int rowCount = 3;
			int colCount = 3;
			int** test_q = new int* [rowCount];
			for (int k = 0; k < rowCount; k++)
				test_q[k] = new int[colCount];
			test_q[0][0] = 62;
			test_q[0][1] = 14;
			test_q[0][2] = 7;
			test_q[1][0] = 20;
			test_q[1][1] = 13;
			test_q[1][2] = 40;
			test_q[2][0] = 11;
			test_q[2][1] = 6;
			test_q[2][2] = 25;
			int actualSum = FindAndSumMins(test_q, rowCount, colCount);
			Assert::AreEqual(18, actualSum);
			for (int k_idx = 0; k_idx < rowCount; k_idx++)
				delete[] test_q[k_idx];
			delete[] test_q;
		}
	};
}
