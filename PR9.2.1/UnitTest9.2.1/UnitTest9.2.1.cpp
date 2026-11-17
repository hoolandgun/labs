#include "pch.h"
#include "CppUnitTest.h"
#define LINK_TEST
#include "D:\Проєкти VSC++\PR9.2.1\PR9.2.1\macros.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest921
{
	TEST_CLASS(UnitTest921)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double actual = SQR(4.0);
			Assert::AreEqual(16.0, actual, 0.0001);
		}
	};
}
