#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    
    cout << "Execution trace of sin(x) loop:\n";

    // [1] Initialization: Executes ONCE at the start.
    // [2] Condition: Evaluated before every loop. If true, the loop runs.
    // [3] Body: The code inside the brackets that executes.
    // [4] Increment: Updates the variable, then goes back to step [2].

    for (double x = 0.0; /* [1] */ x <= 90.0; /* [2] */ x += 15.0 /* [4] */) 
    {
        // --- [3] Body Execution Starts ---
        double radians = x * M_PI / 180.0;
        cout << "Value of sin(" << x << "): " << sin(radians) << endl;
        // --- [3] Body Execution Ends ---
    }

    cin.get();
    return 0;
}