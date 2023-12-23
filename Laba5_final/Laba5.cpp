#include <iostream>
#include "integ.h"


using namespace std;

int main()
{
    double integ1 = IntegTrap(1.0, 2.835);
    cout << "Integral 1: " << integ1 << endl;

    double integ2 = IntegSimpson(1.0, 2.835);
    cout << "Integral 2: " << integ2 << endl;

    double integ3 = IntegSimpson2(100, 100, 0.0, 4.0, 1.0, 2.0);
    cout << "Integral 3: " << integ3 << endl;
}