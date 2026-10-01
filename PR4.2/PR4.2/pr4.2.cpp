#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double x, xp, xk, dx, A, B, y;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << fixed;
	cout << "--------------------" << endl;
	cout << "|" << setw(8) << "x" << " |"
		<< setw(8) << "y" << " |" << endl;
	cout << "--------------------" << endl;
	x = xp;
	while (x <= xk)
	{
		A = 2 * fabs(5 - x);
		
		if (x <= -1)
			B = exp(fabs(2 + x));  
		else 
			if (x >= 1)
				B = (pow(cos(x), 2)) / (1 + fabs(sin(x)));  
			else 
				B = pow(sin(1. / fabs(2 + x)), 2); 
		y = A - B; 
		cout << "|" << setw(8) << setprecision(2) << x
			<< " |" << setw(8) << setprecision(3) << y
			<< " |" << endl;
		x += dx;
	}
	cout << "--------------------" << endl;
		return 0; 
}