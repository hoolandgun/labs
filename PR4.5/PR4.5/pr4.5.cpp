#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;
int main()
{
	double x, y, R;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		cout << "x = "; cin >> x;
		cout << "y = "; cin >> y;
		cout << "R = "; cin >> R;
		if (((0 <= y) && (0 <= x) && (R * R >= pow(y, 2) + pow(x, 2))) || ((y <= 0) && (x <= 0) && (y >= -1 * (x + R))))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	cout << endl << fixed;

	cout << "R = "; cin >> R;
	for (int i = 0; i < 10; i++)
	{
		    x = (2. * R) * rand() / RAND_MAX - R;
            y = (2. * R) * rand() / RAND_MAX - R;

			if (((0 <= y) && (0 <= x) && (R * R >= pow(y, 2) + pow(x, 2))) || ((y <= 0) && (x <= 0) && (y >= -1 * (x + R))))
			{
				cout << setw(8) << setprecision(4) << x << " "
					<< setw(8) << setprecision(4) << y << " " 
					<< setw(8) << setprecision(4) << R << " " << "yes" << endl;
			}
			else 
			{
				cout << setw(8) << setprecision(4) << x << " "
					<< setw(8) << setprecision(4) << y << " " 
					<< setw(8) << setprecision(4) << R << " " << "no" << endl;
			}
			
		}
	return 0;
}