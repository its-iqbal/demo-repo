#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x = 25.0;

    cout << sqrt(25.0) << endl;

    cout << sqrt(x) << endl;

    cout << sqrt(2 * x - 5) << endl;    //45

    double y = sqrt(x); //5

    y = 2 * sqrt(x + 16) - 4;

    y = sqrt(sqrt(256.0));

    cout << y << endl;

    cin.get();
    return 0;
}