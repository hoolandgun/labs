#include <iostream>
#include "macros.h"

using namespace std;

#define Z 3

#ifndef LINK_TEST
int main() {
    double x, y, w;

    cout << "Z = " << Z << " (defined via #define)" << endl;
    cout << "X = ";
    cin >> x;
    cout << "Y = ";
    cin >> y;

#if (Z > 0) && (Z < 5)
    w = MIN(SQR(x) + y + Z, x * y * Z);
#else
    w = MAX(SQR(x) + SQR(y + Z), x * y);
#endif

    PRINTR(w);

    return 0;
}
#endif
