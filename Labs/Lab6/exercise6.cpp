/*
EXERCISE 6
- Input a number from the user
- Store each of the digits in an array
- Ask user if even or odd digits should be displayed

E.g.
- Number is 8342116
- Array is {6,1,1,2,4,3,8}
- Odd numbers output is 311
*/

#include <iostream>
#include <array>
#include <cmath>
using namespace std;

int main() {
    int number;
    bool negative = false;

    cout << "Enter a number: ";
    cin >> number;

    if (number < 0) {
        negative = true;
        number *= -1;
    }

    size_t n = 1;
    if (number > 0)
        n += log10(number);
    
    unsigned int digits[n];

    cout << "Digits array: ";
    for (unsigned int& digit : digits) {
        digit = number % 10;
        number /= 10;
        cout << digit << " ";
    }
    cout << endl;

    int choice;
    cout << "Do you want even (0) or odd (1): ";
    cin >> choice;

    while (choice != 0 && choice != 1) {
        cout << "You can only type 0 or 1, please reenter: ";
        cin >> choice;
    }
    
    int result = 0;

    // Loop runs n-1...0
    for (int i = n; i--;) {
        if (digits[i] % 2 == choice) {
            result *= 10;
            result += digits[i];
        }
    }

    if (negative)
        result *= -1;

    cout << result << endl;
}