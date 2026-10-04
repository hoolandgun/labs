#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	double xp, xk, dx;
	double x;
	double y; 
	double R; 
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "x = "; cin >> x;
	cout << "R = "; cin >> R;

	cout << fixed;
	cout << "----------------------------" << endl;
		cout << "|" << setw(8) << "x" << "|"
		<< setw(8) << "y" << "|"
		<< setw(8) << "R" << "|"
		<< endl;
		cout << "----------------------------" << endl;
		x = xp;
		while (x <= xk)
		{
			if (x <= -1 - R)
				y = -1 * (x + 1 + R);
			else
				if ((-1 - R) < x && x <= -1)
					y = sqrt(pow(R, 2) - pow((x - -1), 2));
				else
					if (-1 < x && x <= 1)
						y = R;
					else
						if (1 < x && x <= 2)
							y = R + (-1 - R) / (2 - 1) * (x - 1);
						else
							y = -1;
			cout << "|" << setw(8) << setprecision(3) << x
				<< "|" << setw(8) << setprecision(3) << y
				<< "|" << setw(8) << setprecision(3) << R
				<< "|" << endl;
			x += dx;
		}
	cout << "----------------------------" << endl;
	return 0;
}