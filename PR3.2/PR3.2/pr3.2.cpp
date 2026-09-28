#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x, a, b, c, F;

	cout << "x = "; cin >> x;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;

	if (!((x < 1 && c == 0) || (1 <= x && x <= 1.5 && c == 0)))
	{
		// спосіб 1: скорочена форма 
		if (x < 1)
			F = a * pow(x, 2) + (b / c);
		if (x > 1.5 && c == 0)
			F = (x - a) / pow((x - c), 2);
		if (x >= 1 && c != 0) 
			F = pow(x, 2) / pow(c, 2);

		cout << "1) F = " << F << endl;

		// спосіб 2: повна форма 
		if (x < 1)
			F = a * pow(x, 2) + (b / c);
		else if (x > 1.5 && c == 0)
			F = (x - a) / pow((x - c), 2);
		else 
			F = pow(x, 2) / pow(c, 2);

		cout << "2) F = " << F << endl;
	}
	else
	{
		cout << "ERROR: Division by zero!" << endl;
	}

	cin.get();
	return 0;
}
