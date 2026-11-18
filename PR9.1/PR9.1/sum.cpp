#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace nsDod;
using namespace nsVar;

void nsSum::sum() {
    n = 0;
    a = 1.0 / x;
    S = a;
    do {
        n++;
        dod();
        S += a;
    } while (fabs(a) >= eps);
}