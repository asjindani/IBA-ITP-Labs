/*
EXERCISE 2
Check Factors
*/

#include <iostream>
using namespace std;

bool isFactor(int, int);

int main() {
    int n1, n2;

    cout << "Enter two numbers (write 'x' to exit): ";
    while (cin >> n1 >> n2) {
        cout << n2 << " is " << (isFactor(n1,n2) ? "" : "not ") << "a factor of " << n1 << endl;
        cout << "Enter two numbers (write 'x' to exit): ";
    }
}

bool isFactor(int a, int b) {
    return a % b == 0;
}