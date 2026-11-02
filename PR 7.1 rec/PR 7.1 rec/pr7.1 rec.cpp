#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void AllocateMemory(int** q, const int rowCount, const int colCount, int k);
void FreeMemory(int** q, const int rowCount, int k);
void Create(int** q, const int rowCount, const int colCount,
	const int Low, const int High, int k, int n);
void Print(int** q, const int rowCount, const int colCount, int k, int n);
void Sort(int** q, const int rowCount, const int colCount, int j0);
void Change(int** q, const int col1, const int col2, const int rowCount, int i);
void Calc(int** q, const int rowCount, int colCount, int i, int& S, int& k);

#ifndef LINK_TEST
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 62;
	int rowCount = 7;
	int colCount = 6;
	int** q = new int* [rowCount];
	AllocateMemory(q, rowCount, colCount, 0);

	Create(q, rowCount, colCount, Low, High, 0, 0);
	cout << endl;
	Print(q, rowCount, colCount, 0, 0);

	Sort(q, rowCount, colCount, 0);
	Print(q, rowCount, colCount, 0, 0);
	int S = 0;
	int k = 0;
	Calc(q, rowCount, colCount, 0, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;

	Print(q, rowCount, colCount, 0, 0);
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

void SortInner(int** q, const int rowCount, const int colCount, int j0, int j1)
{
	if (j1 >= colCount - j0 - 1) return;
	if ((q[0][j1] < q[0][j1 + 1])
		||
		(q[0][j1] == q[0][j1 + 1] && q[1][j1] > q[1][j1 + 1])
		||
		(q[0][j1] == q[0][j1 + 1] && q[1][j1] == q[1][j1 + 1] && q[2][j1] > q[2][j1 + 1]))
	{
		Change(q, j1, j1 + 1, rowCount, 0);
	}
	SortInner(q, rowCount, colCount, j0, j1 + 1);
}

void Sort(int** q, const int rowCount, const int colCount, int j0)
{
	if (j0 >= colCount - 1) return;
	SortInner(q, rowCount, colCount, j0, 0);
	Sort(q, rowCount, colCount, j0 + 1);
}


void Change(int** q, const int col1, const int col2, const int rowCount, int i)
{
	if (i >= rowCount) return;
	int tmp = q[i][col1];
	q[i][col1] = q[i][col2];
	q[i][col2] = tmp;
	Change(q, col1, col2, rowCount, i + 1);
}

void CalcInner(int** q, const int colCount, int i, int j, int& S, int& k)
{
	if (j >= colCount) return;
	if (q[i][j] % 2 == 0 && !((i + j) % 8 == 0))
	{
		S += q[i][j];
		k++;
		q[i][j] = 0;
	}
	CalcInner(q, colCount, i, j + 1, S, k);
}

void Calc(int** q, const int rowCount, int colCount, int i, int& S, int& k)
{
	if (i >= rowCount) return;
	CalcInner(q, colCount, i, 0, S, k);
	Calc(q, rowCount, colCount, i + 1, S, k);
}