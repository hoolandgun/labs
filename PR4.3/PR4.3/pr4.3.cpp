#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double x, xp, xk, dx, a, b, c, F;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;
	cout << fixed;
	cout << "----------------------------------------------" << endl;
	cout << "|" << setw(8) << "a" << "|" 
		<< setw(8) << "b" << "|" 
		<< setw(8) << "c" << "|"
		<< setw(8) << "x" << "|"
		<< setw(8) << "F" << "|"
		<< endl;
	cout << "----------------------------------------------" << endl;
	x = xp;
	while (x <= xk)
	{
		if (x < 1 && c != 0)
			F = a * x * x + b / c;
		else
			if (x > 1.5 && c == 0)
				F = (x - a) / (pow((x - c), 2));
			else
				F = (x * x) / (c * c);
		cout << "|" << setw(8) << setprecision(3) << a
			<< "|" << setw(8) << setprecision(3) << b
			<< "|" << setw(8) << setprecision(3) << c
			<< "|" << setw(8) << setprecision(2) << x
			<< "|" << setw(8) << setprecision(2) << F
			<< "|" << endl;
		x += dx;
	}
	cout << "----------------------------------------------" << endl;
	return 0;
}