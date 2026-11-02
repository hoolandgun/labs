#include "pch.h"
#include "CppUnitTest.h"
#define LINK_TEST
#include "D:\Проєкти VSC++\PR7.1 it\PR7.1 it\pr7.1 it.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71it
{
	TEST_CLASS(UnitTest71it)
	{
	public:
		
		TEST_METHOD(TestCalc)
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
			int S = 0;
			int k = 0;
			Calc(test_q, rowCount, colCount, S, k);
			Assert::AreEqual(80, S);
			Assert::AreEqual(4, k);
			Assert::AreEqual(62, test_q[0][0]);
			Assert::AreEqual(0, test_q[0][1]);
			Assert::AreEqual(0, test_q[1][0]);
			Assert::AreEqual(0, test_q[1][2]);
			Assert::AreEqual(0, test_q[2][1]);
			for (int k_idx = 0; k_idx < rowCount; k_idx++)
				delete[] test_q[k_idx];
			delete[] test_q;
		}
	};
}
