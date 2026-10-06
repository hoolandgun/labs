#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
	int n = 0;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

	if (fabs(xp) <= 1 || fabs(xk) <= 1) {
		cout << "ERROR: |x| must be > 1" << endl;
		return 0;
	}

	cout << fixed;
	cout << "-----------------------------------------" << endl;
	cout << "|" << setw(7) << "x" << " |"
		<< setw(10) << "Arcth(x)" << " |"
		<< setw(10) << "S" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "-----------------------------------------" << endl;
	x = xp;
	while (x <= xk)
	{
		n = 0;
		a = 1. / x;
		S = a;
		do {
			n++;
			R = (2.0 * n - 1.0) / ((2.0 * n + 1.0) * x * x);
			a *= R;
			S += a;
		} while (abs(a) >= eps);
		double Arcth = 0.5 * log((x + 1.0) / (x - 1.0));
		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(5) << Arcth << " |"
			<< setw(10) << setprecision(5) << S << " |"
			<< setw(5) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "-----------------------------------------" << endl;
	return 0;
}