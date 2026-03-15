#include <iostream>

using namespace std;

int main()
{

    cout << "------------------------------------------" << endl;
    cout << "DATA TYPE\t\tSIZE (IN BYTES)" << endl;
    cout << "------------------------------------------" << endl;

    cout << "char \t\t\t" << sizeof(char) << endl;
    cout << "int \t\t\t" << sizeof(int) << endl;
    cout << "short int \t\t" << sizeof(short int) << endl;
    cout << "long int \t\t" << sizeof(long int) << endl;
    cout << "long long int \t\t" << sizeof(long long int) << endl;
    cout << "float \t\t\t" << sizeof(float) << endl;
    cout << "double \t\t\t" << sizeof(double) << endl;
    cout << "long double \t\t" << sizeof(long double) << endl;
    cout << "bool \t\t\t" << sizeof(bool) << endl;
    cout << "string \t\t\t" << sizeof(string) << endl;

    cout << "------------------------------------------" << endl;

    cin.get();
    return 0;
}