#include <iostream>          // Header file for standard input-output stream
using namespace std;         // Standard library to use cout and cin without std:: prefix

int main() {                 // Main function: where the program execution starts
    int num;                 // Variable declaration (integer type)

    // Output statement to prompt the user
    cout << "Enter a number: "; 
    
    // Input statement: takes value from keyboard and stores it in 'num'
    cin >> num;              

    // Loop starts at 1, runs while i is 10 or less, and increments i by 1 each time
    for (int i = 1; i <= 10; i++) { 
        
        // Breakdown of the output line:
        // num      -> prints the chosen number
        // " x "    -> prints the multiplication symbol as a string
        // i        -> prints the current loop count (1 to 10)
        // " = "    -> prints the equals sign
        // num * i  -> the calculation (multiplication)
        // endl     -> ends the line and moves to the next
        cout << num << " x " << i << " = " << num * i << endl;
    } 

    cin.ignore();
    cin.get();
    return 0;                // Signals that the program executed successfully
}                            // End of main function block