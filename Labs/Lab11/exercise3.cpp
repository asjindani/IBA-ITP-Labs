/*
Exercise 3
Sum of harmonic series using recursion
*/

#include <iostream>
using namespace std;

double sumTo(unsigned int);

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number < 1) {
        cout << "Number must be positive";
        return 0;
    }

    for (int i = 1; i <= number; i++) {
        cout << "1/" << i << " + ";
    }

    cout << "\b\b\b" << " = ";
    cout << sumTo(number) << endl;
}

double sumTo(unsigned int n) {
    if (n == 0)
        return 0.0;
    return 1.0/n + sumTo(n-1);
}