// Lab_03_4.cpp
// < Косанюк Богдан >
// Лабораторна робота № 3.4
// Розгалуження, задане плоскою фігурою.
// Варіант 11
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x; // вхідний аргумент
	double y; // вхідний параметр
	double R; // вхідний параметр
	
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;
	cout << "R = "; cin >> R;

	// розгалуження в повній формі
	if ((((0 <= y && y <= R) && (0 <= x && x <= R)) && (R >= sqrt(pow(y, 2) + pow(x, 2)))) ||
		
		
		(((-R <= y && y <= 0) && (-R <= x && x <= 0)) && (y >= -1 * (x + R))))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	cin.get();
	return 0;
}