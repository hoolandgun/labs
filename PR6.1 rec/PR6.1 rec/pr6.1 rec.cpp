#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else cout << endl;
}
int Num(int* a, const int size, int i)
{
	if (i < size) 
	{
		int N = (a[i] > 0 || a[i] % 2 != 0) ? 1 : 0;
		return Num(a, size, i + 1);
	}
	return 0;
}

int Sum(int* a, const int size, int i)
{
	if (i < size)
	{
		int S = (a[i] > 0 || a[i] % 2 != 0) ? a[i] : 0;
		return S + Sum(a, size, i + 1);
	}
	return 0;
}

void Revers(int* a, const int size, int i)
{
	if (a[i] > 0 || a[i] % 2 != 0)
		a[i] = 0;
	if (i < size - 1)
		Revers(a, size, i + 1);
}
#ifndef LINK_TEST
int main()
{
	srand((unsigned)time(NULL));
	const int n = 27;
	int с[n];
	int Low = -35;
	int High = 25;
	Create(с, n, Low, High, 0);
	Print(с, n, 0);
	cout << endl;
	cout << "N = " << Num(с, n, 0) << endl;
	cout << "S = " << Sum(с, n, 0) << endl;
	Revers(с, n, 0);
	Print(с, n, 0);

	return 0;
}
#endif