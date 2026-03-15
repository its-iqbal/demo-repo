#include <iostream>
#include <cmath>
using namespace std;

int main() {
   
    float radius = 5.0f;
    float cx = 0.0f, cy = 0.0f;
    const float PI = 3.1415926f;

    cout << "Calculating Vertices for a Circle (Radius: " << radius << ")\n";
    cout << "--------------------------------------------------\n";

    
    for (int i = 0; i <= 360; i += 45) { 
        
        float theta = i * PI / 180.0f; 
       
        float x = cx + radius * cos(theta);
        float y = cy + radius * sin(theta);
        
        cout << "Angle " << i << " degrees : (" << x << ", " << y << ")\n";
    }

    cin.get();
    return 0;
}