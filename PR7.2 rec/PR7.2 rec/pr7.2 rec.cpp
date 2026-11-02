#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void AllocateMemory(int** q, const int rowCount, const int colCount, int k);
void FreeMemory(int** q, const int rowCount, int k);
void Create(int** q, const int rowCount, const int colCount,
	const int Low, const int High, int k, int n);
void Print(int** q, const int rowCount, const int colCount, int k, int n);
int ColMin(int** q, const int rowCount, int k, int n, int min);
void FindMin(int** q, const int rowCount, int& min0, int& min2, int& min4, int& min6);
int SumOfMins(const int m0, const int m2, const int m4, const int m6);

#ifndef LINK_TEST
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 62;
	int rowCount = 7;
	int colCount = 8;

	int** q = new int* [rowCount];
	AllocateMemory(q, rowCount, colCount, 0);

	Create(q, rowCount, colCount, Low, High, 0, 0);
	cout << endl;
	Print(q, rowCount, colCount, 0, 0);

	int min, min0, min2, min4, min6;
	FindMin(q, rowCount, min0, min2, min4, min6);

	int totalSum = SumOfMins(min0, min2, min4, min6);

	cout << min0 << " + " << min2 << " + " << min4 << " + " << min6 << " = " << totalSum << endl;

	FreeMemory(q, rowCount, 0);
	delete[] q;
	return 0;
}
#endif

void AllocateMemory(int** q, const int rowCount, const int colCount, int k)
{
	if (k >= rowCount) return;
	q[k] = new int[colCount];
	AllocateMemory(q, rowCount, colCount, k + 1);
}

void FreeMemory(int** q, const int rowCount, int k)
{
	if (k >= rowCount) return;
	delete[] q[k];
	FreeMemory(q, rowCount, k + 1);
}

void Create(int** q, const int rowCount, const int colCount,
	const int Low, const int High, int k, int n)
{
	q[k][n] = Low + rand() % (High - Low + 1);
	if (n < colCount - 1)
		Create(q, rowCount, colCount, Low, High, k, n + 1);
	else
		if (k < rowCount - 1)
			Create(q, rowCount, colCount, Low, High, k + 1, 0);
}

void Print(int** q, const int rowCount, const int colCount, int k, int n)
{
	cout << setw(4) << q[k][n];
	if (n < colCount - 1)
		Print(q, rowCount, colCount, k, n + 1);
	else
		if (k < rowCount - 1)
		{
			cout << endl;
			Print(q, rowCount, colCount, k + 1, 0);
		}
		else
			cout << endl << endl;
}

int ColMin(int** q, const int rowCount, int k, int n, int min)
{
	if (k >= rowCount) return min;
	if (q[k][n] < min)
		min = q[k][n];
	return ColMin(q, rowCount, k + 1, n, min);
}

void FindMin(int** q, const int rowCount, int& min0, int& min2, int& min4, int& min6)
{
	min0 = ColMin(q, rowCount, 1, 0, q[0][0]);
	min2 = ColMin(q, rowCount, 1, 2, q[0][2]);
	min4 = ColMin(q, rowCount, 1, 4, q[0][4]);
	min6 = ColMin(q, rowCount, 1, 6, q[0][6]);
}

int SumOfMins(const int m0, const int m2, const int m4, const int m6)
{
	return m0 + m2 + m4 + m6;
}
