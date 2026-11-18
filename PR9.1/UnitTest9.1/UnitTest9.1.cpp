#include "pch.h"
#include "CppUnitTest.h"
#define LINK_TEST
#include "D:\Проєкти VSC++\PR9.1\PR9.1\var.cpp"
#include "D:\Проєкти VSC++\PR9.1\PR9.1\var.h"
#include "D:\Проєкти VSC++\PR9.1\PR9.1\dod.h"
#include "D:\Проєкти VSC++\PR9.1\PR9.1\dod.cpp"
#include "D:\Проєкти VSC++\PR9.1\PR9.1\pr9.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91
{
	TEST_CLASS(UnitTest91)
	{
	public:
		
		TEST_METHOD(TestDod)
		{
			x = 2.0;
			n = 1;
			a = 1.0 / x; 

			dod();

			double expected = 1.0 / 24.0;
			Assert::AreEqual(expected, a, 0.00001);
		}
	};
}
