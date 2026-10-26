#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* a, const int size, const int Low, const int High);
void Print(int* a, const int size);

// Спосіб 1
int DoSwap(int* a, const int size, int current, int finish);
int CompareWithPervious(int* a, int big, int finish);
void SwapNext(int* a, int big, int swap);
void SetBig(int* a, int swap, int key);
void Sort(int* a, const int size);

// Спосіб 2
template <typename T> int DoSwap(T* a, const int size, int current, int finish);
template <typename T> int CompareWithPervious(T* a, int big, int finish);
template <typename T> void SwapNext(T* a, int big, int swap);
template <typename T> void SetBig(T* a, int swap, T key);
template <typename T> void Sort(T* a, const int size);

#ifndef LINK_TEST
int main()
{
	srand((unsigned)time(NULL));
	int Low = -10, High = 10;
	const int n = 10;

	cout << "Method 1 (Regular int)" << endl;
	int* a = new int[n];
	Create(a, n, Low, High);
	Print(a, n);
	Sort(a, n);
	Print(a, n);
	delete[] a;

	cout << "Method 2 (Template int)" << endl;
	int* b = new int[n];
	Create(b, n, Low, High);
	Print(b, n);
	Sort<int>(b, n);
	Print(b, n);
	delete[] b;
	cout << "Method 2 (Template double)" << endl;
	double* c = new double[n];
	double LowD = -10.0, HighD = 10.0;

	for (int i = 0; i < n; i++) {
		c[i] = Low + rand() % (High - Low + 1) + (rand() % 10) / 10.0;
	}
	for (int i = 0; i < n; i++) cout << setw(6) << setprecision(1) << fixed << c[i];
	cout << endl;

	Sort<double>(c, n);

	for (int i = 0; i < n; i++) cout << setw(6) << setprecision(1) << fixed << c[i];
	cout << endl;

	delete[] c;
	return 0;
}
#endif


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

// Спосіб 1
int DoSwap(int* a, const int size, int current, int finish)
{
	for (int i = current + 1; i < size; i++)
		if (a[i] < a[i - 1]) return i;
	return finish;
}

int CompareWithPervious(int* a, int big, int finish)
{
	for (int i = big - 1; i >= 0; i--)
		if (a[i] <= a[big]) return i + 1;
	return finish;
}

void SwapNext(int* a, int big, int swap)
{
	for (int i = big; i > swap; i--)
		a[i] = a[i - 1];
}

void SetBig(int* a, int swap, int key)
{
	a[swap] = key;
}

void Sort(int* a, const int size)
{
	for (int i = 0; i < size; i++)
	{
		int big = DoSwap(a, size, i, size);
		if (big == size) break;
		int swap = CompareWithPervious(a, big, 0);
		int key = a[big];
		SwapNext(a, big, swap);
		SetBig(a, swap, key);
	}
}

// Спосіб 2
template <typename T>
int DoSwap(T* a, const int size, int current, int finish)
{
	for (int i = current + 1; i < size; i++)
		if (a[i] < a[i - 1]) return i;
	return finish;
}

template <typename T>
int CompareWithPervious(T* a, int big, int finish)
{
	for (int i = big - 1; i >= 0; i--)
		if (a[i] <= a[big]) return i + 1;
	return finish;
}

template <typename T>
void SwapNext(T* a, int big, int swap)
{
	for (int i = big; i > swap; i--)
		a[i] = i - 1 >= 0 ? a[i - 1] : a[i];
}

template <typename T>
void SetBig(T* a, int swap, T key)
{
	a[swap] = key;
}

template <typename T>
void Sort(T* a, const int size)
{
	for (int i = 0; i < size; i++)
	{
		int big = DoSwap(a, size, i, size);
		if (big == size) break;
		int swap = CompareWithPervious(a, big, 0);
		T key = a[big];
		SwapNext(a, big, swap);
		SetBig(a, swap, key);
	}
}
