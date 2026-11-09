#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void AllocateMemory(int** q, const int rowCount, const int colCount, int k);
void FreeMemory(int** q, const int rowCount, int k);
void Create(int** q, const int rowCount, const int colCount, const int Low, const int High, int k, int n);
void Print(int** q, const int rowCount, const int colCount, int k, int n);

int FindMin(int** q, const int rowCount, int n, int k, int currentMin);
int FindAndSumMinsRec(int** q, const int rowCount, const int colCount, int n);

#ifndef LINK_TEST
int main()
{
	srand((unsigned)time(NULL));

	int rowCount, colCount;
	cout << "Enter row count: "; cin >> rowCount;
	cout << "Enter col count: "; cin >> colCount;

	if (colCount < 1 || rowCount < 1)
	{
		cout << "Please correct entered data!";
		return -1;
	}

	int Low, High;
	cout << "Enter minimal random value (Low): "; cin >> Low;
	cout << "Enter maximal random value (High): "; cin >> High;

	if (High < Low)
	{
		cout << "High must be bigger than Low!";
		return -1;
	}

	int** q = new int* [rowCount];

	AllocateMemory(q, rowCount, colCount, 0);
	Create(q, rowCount, colCount, Low, High, 0, 0);

	cout << endl;
	Print(q, rowCount, colCount, 0, 0);

	int totalSum = FindAndSumMinsRec(q, rowCount, colCount, 0);

	cout << "Sum of minimums in even columns = " << totalSum << endl;

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

void Create(int** q, const int rowCount, const int colCount, const int Low, const int High, int k, int n)
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

int FindMin(int** q, const int rowCount, int n, int k, int currentMin)
{
	if (k >= rowCount)
		return currentMin;
	if (q[k][n] < currentMin)
		currentMin = q[k][n];
	return FindMin(q, rowCount, n, k + 1, currentMin);
}

int FindAndSumMinsRec(int** q, const int rowCount, const int colCount, int n)
{
	if (n >= colCount)
		return 0;

	int min = FindMin(q, rowCount, n, 1, q[0][n]);
	cout << "Min in col " << n << " = " << min << endl;

	return min + FindAndSumMinsRec(q, rowCount, colCount, n + 2);
}
