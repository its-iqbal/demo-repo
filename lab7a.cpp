#include <iostream>
using namespace std;

int main() {
 
    int myGrid[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (int row = 0; row < 2; row++) {
        
        for (int col = 0; col < 3; col++) {
            
            cout << myGrid[row][col] << " ";
        }
        
        cout << endl;
    }

    cin.get();
    return 0;
}