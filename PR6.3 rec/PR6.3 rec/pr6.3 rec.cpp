#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Спосіб 1
void Create(int* a, const int size, const int Low, const int High, int i = 0);
void Print(int* a, const int size, int i = 0);
int DoSwap(int* a, const int size, int i);
int CompareWithPervious(int* a, int big, int i);
void SwapNext(int* a, int i, int swap);
void SetBig(int* a, int swap, int key);
void Sort(int* a, const int size, int i = 0);

// Спосіб 2
template <typename T> void Create(T* a, const int size, const T Low, const T High, int i = 0);
template <typename T> void Print(T* a, const int size, int i = 0);
template <typename T> int DoSwap(T* a, const int size, int i);
template <typename T> int CompareWithPervious(T* a, int big, int i);
template <typename T> void SwapNext(T* a, int i, int swap);
template <typename T> void SetBig(T* a, int swap, T key);
template <typename T> void Sort(T* a, const int size, int i = 0);

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
	Create<int>(b, n, Low, High);
	Print<int>(b, n);
	Sort<int>(b, n);
	Print<int>(b, n);
	delete[] b;

	cout << "Method 2 (Template double)" << endl;
	double* c = new double[n];
	double LowD = -10.0, HighD = 10.0;
	Create<double>(c, n, LowD, HighD);
	Print<double>(c, n);
	Sort<double>(c, n);
	Print<double>(c, n);
	delete[] c;

	return 0;
}
#endif

// Спосіб 1
void Create(int* a, const int size, const int Low, const int High, int i) {
	if (i >= size) return;
	a[i] = Low + rand() % (High - Low + 1);
	Create(a, size, Low, High, i + 1);
}
void Print(int* a, const int size, int i) {
	if (i >= size) { cout << endl; return; }
	cout << setw(6) << a[i];
	Print(a, size, i + 1);
}
int DoSwap(int* a, const int size, int i) {
	if (i >= size) return size;
	if (a[i] < a[i - 1]) return i;
	return DoSwap(a, size, i + 1);
}
int CompareWithPervious(int* a, int big, int i) {
	if (i < 0) return 0;
	if (a[i] <= a[big]) return i + 1;
	return CompareWithPervious(a, big, i - 1);
}
void SwapNext(int* a, int i, int swap) {
	if (i <= swap) return;
	a[i] = a[i - 1];
	SwapNext(a, i - 1, swap);
}
void SetBig(int* a, int swap, int key) {
	a[swap] = key;
}
void Sort(int* a, const int size, int i) {
	if (i >= size) return;
	int big = DoSwap(a, size, i + 1);
	if (big == size) return;
	int swap = CompareWithPervious(a, big, big - 1);
	int key = a[big];
	SwapNext(a, big, swap);
	SetBig(a, swap, key);
	Sort(a, size, i + 1);
}

// Спосіб 2
template <typename T>
void Create(T* a, const int size, const T Low, const T High, int i) {
	if (i >= size) return;
	a[i] = Low + static_cast<T>(rand() % 100 / 10.0);
	Create(a, size, Low, High, i + 1);
}
template <typename T>
void Print(T* a, const int size, int i) {
	if (i >= size) { cout << endl; return; }
	cout << setw(6) << setprecision(1) << fixed << a[i];
	Print(a, size, i + 1);
}
template <typename T>
int DoSwap(T* a, const int size, int i) {
	if (i >= size) return size;
	if (a[i] < a[i - 1]) return i;
	return DoSwap(a, size, i + 1);
}
template <typename T>
int CompareWithPervious(T* a, int big, int i) {
	if (i < 0) return 0;
	if (a[i] <= a[big]) return i + 1;
	return CompareWithPervious(a, big, i - 1);
}
template <typename T>
void SwapNext(T* a, int i, int swap) {
	if (i <= swap) return;
	a[i] = a[i - 1];
	SwapNext(a, i - 1, swap);
}
template <typename T>
void SetBig(T* a, int swap, T key) {
	a[swap] = key;
}
template <typename T>
void Sort(T* a, const int size, int i) {
	if (i >= size) return;
	int big = DoSwap(a, size, i + 1);
	if (big == size) return;
	int swap = CompareWithPervious(a, big, big - 1);
	T key = a[big];
	SwapNext(a, big, swap);
	SetBig(a, swap, key);
	Sort(a, size, i + 1);
}
