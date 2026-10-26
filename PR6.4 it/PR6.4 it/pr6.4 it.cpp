#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(double* c, const int size, const double Low, const double High)
{
	for (int i = 0; i < size; i++)
		c[i] = Low + (double)rand() / RAND_MAX * (High - Low);
}

void Print(double* c, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(8) << fixed << setprecision(2) << c[i];
	cout << endl;
}

// 1 завдання

int FindMin(double* c, const int size)
{
	int imin = 0;
	for (int i = 1; i < size; i++)
		if (fabs(c[i]) < fabs(c[imin]))
			imin = i;
	return imin;
}

int FindFirstNegative(double* c, const int size)
{
	for (int i = 0; i < size; i++)
		if (c[i] < 0)
			return i;
	return -1;
}

double SumFabs(double* c, const int size, int ineg)
{
	if (ineg == -1 || ineg >= size - 1)
	{
		cout << "Sum = " << endl;
		return 0.0;
	}
	double Sum = 0.0;
	for (int i = ineg + 1; i < size; i++)
	{
		cout << fixed << setprecision(2) << fabs(c[i]);

		if (i < size - 1)
			cout << " + ";
		else
			cout << " = ";

		Sum += fabs(c[i]);
	}

	return Sum;
}

// 2 завдання

int NonTheRange(double* c, const int size, const double a, const double b, int* notintherange)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (!(a <= c[i] && c[i] <= b))
		{
			notintherange[count] = i;
			count++;
		}
	return count;
}

void SetElements(double* c, int count, int* notintherange)
{
	for (int i = 0; i < count; i++)
		c[i] = c[notintherange[i]];
}

void FillZeros(double* c, const int size, int count)
{
	for (int i = count; i < size; i++)
	{
		c[i] = 0.0;
	}
}

#ifndef LINK_TEST
int main()
{
	srand((unsigned)time(NULL));
	int Low = -20;
	int High = +20;
	int n, a, b;
	cout << "n = "; cin >> n;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b; cout << endl;
	double* c = new double[n];
	int* notintherange = new int[n];
	Create(c, n, Low, High);
	Print(c, n);	
	cout << endl;
	int imin = FindMin(c, n);
	int ineg = FindFirstNegative(c, n);
	cout << "Sum = ";
	double Sum = SumFabs(c, n, ineg);
	cout << fixed << setprecision(2) << Sum << endl;
	cout << endl;
	int count = NonTheRange(c, n, a, b, notintherange);
	SetElements(c, count, notintherange);
	FillZeros(c, n, count);
	Print(c, n);
	delete[] c;
	delete[] notintherange;
	return 0;
}
#endif