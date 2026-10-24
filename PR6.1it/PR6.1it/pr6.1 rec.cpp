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

int Num(int* a, const int size)
{
	int N = 0;
	for (int i = 0; i < size; i++)
		if (a[i] > 0 || a[i] % 2 != 0)
			N++;
	return N;
}

int Sum(int* a, const int size)
{
	int S = 0;
	for (int i = 0; i < size; i++)
		if (a[i] > 0 || a[i] % 2 != 0)
			S += a[i];
	return S;
}

void Revers(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		if (a[i] > 0 || a[i] % 2 != 0)
			a[i] = 0;
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 27;
	int a[n];
	int Low = -35;
	int High = 25;
	Create(a, n, Low, High);
	Print(a, n);
	cout << "N = " << Num(a, n) << endl;
	cout << "S = " << Sum(a, n) << endl;
	Revers(a, n);
	Print(a, n);

	return 0;
}

