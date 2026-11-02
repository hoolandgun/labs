#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** q, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** q, const int rowCount, const int colCount);
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
	for (int k = 0; k < rowCount; k++)
		q[k] = new int[colCount];

	Create(q, rowCount, colCount, Low, High);
	Print(q, rowCount, colCount);

	int min0, min2, min4, min6;
	FindMin(q, rowCount, min0, min2, min4, min6);

	int totalSum = SumOfMins(min0, min2, min4, min6);

	cout << min0 << " + " << min2 << " + " << min4 << " + " << min6 << " = " << totalSum << endl;

	for (int k = 0; k < rowCount; k++)
		delete[] q[k];
	delete[] q;
	return 0;
}
#endif

void Create(int** q, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int k = 0; k < rowCount; k++)
		for (int n = 0; n < colCount; n++)
			q[k][n] = Low + rand() % (High - Low + 1);
}

void Print(int** q, const int rowCount, const int colCount)
{
	cout << endl;
	for (int k = 0; k < rowCount; k++)
	{
		for (int n = 0; n < colCount; n++)
			cout << setw(4) << q[k][n];
		cout << endl;
	}
	cout << endl;
}

void FindMin(int** q, const int rowCount, int& min0, int& min2, int& min4, int& min6)
{
	min0 = q[0][0];
	min2 = q[0][2];
	min4 = q[0][4];
	min6 = q[0][6];

	for (int k = 1; k < rowCount; k++)
		if (q[k][0] < min0)
			min0 = q[k][0];

	for (int k = 1; k < rowCount; k++)
		if (q[k][2] < min2)
			min2 = q[k][2];

	for (int k = 1; k < rowCount; k++)
		if (q[k][4] < min4)
			min4 = q[k][4];

	for (int k = 1; k < rowCount; k++)
		if (q[k][6] < min6)
			min6 = q[k][6];
}

int SumOfMins(const int m0, const int m2, const int m4, const int m6)
{
	return m0 + m2 + m4 + m6;
}