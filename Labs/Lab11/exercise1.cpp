/*
Exercise 1
Factorial using recursion
*/

#include <iostream>
using namespace std;

int factorial(unsigned int);

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    if (number < 0) {
        cout << "Number must not be negative" << endl;
        return 0;
    }

    cout << "Factorial of " << number << " is " << factorial(number) << endl;
}

int factorial(unsigned int n) {
    if (n == 0)
        return 1;
    return n * factorial(n-1);
}