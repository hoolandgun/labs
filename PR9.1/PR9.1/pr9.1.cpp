#include <iostream>
#include <iomanip>
#include <cmath>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

#ifndef LINK_TEST
int main() {
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
    while (x <= xk) {
        sum();

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
#endif