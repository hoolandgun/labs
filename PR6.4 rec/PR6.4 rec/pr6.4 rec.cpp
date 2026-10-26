#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>

using namespace std;

void Create(double* c, const int size, const double Low, const double High, int i)
{
	if (i == size)
		return;

	c[i] = Low + (double)rand() / RAND_MAX * (High - Low);
	Create(c, size, Low, High, i + 1);
}

void Print(double* c, const int size, int i)
{
	if (i == size)
	{
		cout << endl;
		return;
	}
	cout << setw(8) << fixed << setprecision(2) << c[i];
	Print(c, size, i + 1);
}

// 1 завдання

int FindMin(double* c, const int size, int i, int imin)
{
	if (i == size)
		return imin;

	if (fabs(c[i]) < fabs(c[imin]))
		imin = i;

	return FindMin(c, size, i + 1, imin);
}

int FindFirstNegative(double* c, const int size, int i)
{
	if (i == size)
		return -1;

	if (c[i] < 0)
		return i;

	return FindFirstNegative(c, size, i + 1);
}

double SumFabs(double* c, const int size, int ineg, int i, double Sum)
{
	if (ineg == -1 || ineg >= size - 1)
	{
		if (i == ineg + 1) cout << "Sum = ";
		return 0.0;
	}

	if (i == size)
		return Sum;

	cout << fixed << setprecision(2) << fabs(c[i]);

	if (i < size - 1)
		cout << " + ";
	else
		cout << " = ";

	return SumFabs(c, size, ineg, i + 1, Sum + fabs(c[i]));
}

// 2 завдання

int NonTheRange(double* c, const int size, const double a, const double b, int* notintherange, int i, int count)
{
	if (i == size)
		return count;

	if (!(a <= c[i] && c[i] <= b))
	{
		notintherange[count] = i;
		count++;
	}

	return NonTheRange(c, size, a, b, notintherange, i + 1, count);
}

void SetElements(double* c, int* notintherange, int count, int i)
{
	if (i == count)
		return;

	c[i] = c[notintherange[i]];
	SetElements(c, notintherange, count, i + 1);
}

void FillZeros(double* c, const int size, int count, int i)
{
	if (i == size)
		return;

	c[i] = 0.0;
	FillZeros(c, size, count, i + 1);
}

#ifndef LINK_TEST
int main()
{
	srand((unsigned)time(NULL));
	double Low = -20.0;
	double High = 20.0;
	int n;
	double a, b;
	cout << "n = "; cin >> n;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	double* c = new double[n];
	int* notintherange = new int[n];
	Create(c, n, Low, High, 0);
	Print(c, n, 0);
	int imin = FindMin(c, n, 1, 0);
	cout << "imin = " << imin << endl;
	int ineg = FindFirstNegative(c, n, 0);
	cout << "Sum = ";
	double Sum = SumFabs(c, n, ineg, ineg + 1, 0.0);
	cout << fixed << setprecision(2) << Sum << endl;
	int count = NonTheRange(c, n, a, b, notintherange, 0, 0);
	SetElements(c, notintherange, count, 0);
	FillZeros(c, n, count, count); 
	Print(c, n, 0);

	delete[] c;
	delete[] notintherange;

	return 0;
}
#endif
