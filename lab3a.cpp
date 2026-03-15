#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
    double x = 45.0;
    double radians = x * M_PI / 180.0;

    cout << "Value of sin(" << x << "): " << sin(radians) << endl;

    cin.get();
    return 0;
}