#include <iostream>
using namespace std;

void renderBitmapScreen(float x, float y, void* font, char* string) {
    
    cout << "Base Address of String: " << (void*)string << "\n\n";

    for (char* c = string; *c != '\0'; c++) {
        cout << "Memory Address: " << (void*)c << " | Character: " << *c << "\n";
    }
}

int main() {
    char myName[] = "Iqbal";
    
    cout << "--- Memory Trace Execution --- \n";
    renderBitmapScreen(0.0, 0.0, NULL, myName);
    
    cin.get();
    return 0;
}