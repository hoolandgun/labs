#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Create(int** q, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** q, const int rowCount, const int colCount);
int FindAndSumMins(int** q, const int rowCount, const int colCount);

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
	for (int k = 0; k < rowCount; k++)
		q[k] = new int[colCount];

	Create(q, rowCount, colCount, Low, High);
	Print(q, rowCount, colCount);

	int totalSum = FindAndSumMins(q, rowCount, colCount);

	cout << "Sum of minimums in even columns = " << totalSum << endl;

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

int FindAndSumMins(int** q, const int rowCount, const int colCount)
{
	int totalSum = 0;
	for (int n = 0; n < colCount; n += 2)
	{
		int min = q[0][n];

		for (int k = 1; k < rowCount; k++)
		{
			if (q[k][n] < min)
				min = q[k][n];
		}

		cout << "Min in col " << n << " = " << min << endl;
		totalSum += min;
	}
	return totalSum;
}
