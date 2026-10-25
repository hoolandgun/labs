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

int First(int* a, const int size, int i = 0)
{
	if (i >= size)
		return -1;
	if (a[i] % 2 != 0)
		return i;
	return First(a, size, i + 1);
}

int FindIMax(int* a, const int size, int max, int imax, int i)
{
	if (i >= size)
	{
		return imax;
	}
	if (a[i] % 2 != 0 && a[i] > max)
	{
		max = a[i];
		imax = i;
	}
    return FindIMax(a, size, max, imax, i + 1);
}

void Swap(int* a, const int size, int imax)
{
	swap(a[imax], a[size - 1]);
}

#ifndef LINK_TEST
int main()
{
	srand((unsigned)time(NULL));
	int Low = -20;
	int High = +20;
	int n;
	cout << "n = ";
	cin >> n;
	int* a = new int[n];
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	int first = First(a, n);
	if (first == -1)
	{
		cout << "There are no odd elements in this array; please restart." << endl;
		delete[] a;
		return 0;
	}
	int imax = FindIMax(a, n, a[first], first, first + 1);
	Swap(a, n, imax);
	Print(a, n, 0);
	delete[] a;
	return 0;
}
#endif