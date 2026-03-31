#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x;
    double y;

    const double PI = 3.14159;
    const double p_x = 100;
    const double p_y = 0;

    const double radian = 10 * PI / 180;

    const double COS10 = cos(radian);
    const double SIN10 = sin(radian);

    cout << "Enter initial satellite coordinates (x y): ";
    cin >> x >> y;

    double d1 = sqrt((p_x - x) * (p_x - x) + (p_y - y) * (p_y - y));

    double x_old = x;

    x = x * COS10 - y * SIN10;

    y = x_old * SIN10 + y * COS10;

    double d2 = sqrt((p_x - x) * (p_x - x) + (p_y - y) * (p_y - y));

    cout << "Difference in distances: " << d1 - d2 << endl;

    cin.get();
    return 0;
}