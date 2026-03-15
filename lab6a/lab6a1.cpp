#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double PI = 3.14159;

    for (int i = 0; i <= 360; i += 30)
    {

        double rad = i * (PI / 180);

        cout << "Angle: " << i << " \t Sin: " << sin(rad) << endl;
    }

    cin.get();
    return 0;
}