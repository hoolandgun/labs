#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}

int First(int* a, const int size)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] % 2 != 0)
			return i;
	}
	return -1;
}

int FindIMax(int* a, const int size, int first_index)
{
	int max = a[first_index];
	int imax = first_index;   
	for (int i = first_index + 1; i < size; i++)
	{
		if (a[i] % 2 != 0 && a[i] > max)
		{
			max = a[i];
			imax = i;
		}
	}
	return imax;
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
	Create(a, n, Low, High);
	Print(a, n);
	int first = First(a, n);
	if (first == -1)
	{
		cout << "There are no odd elements in this array; please restart." << endl;
		delete[] a;
		return 0;
	}
	int imax = FindIMax(a, n, first);
	Swap(a, n, imax);
	Print(a, n);
	delete[] a;
	return 0;
}
#endif