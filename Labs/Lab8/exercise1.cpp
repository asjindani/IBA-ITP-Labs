/*
EXERCISE 1
Count of 7
*/

#include <iostream>
using namespace std;

int count7(int);

int main() {
    int number;
    cout << "Enter a number: ";

    if (cin >> number)
        cout << "Count of 7 in " << number << " is " << count7(number) << "";
    else
        cout << "Invalid number entered";

    cout << endl;
}

int count7(int n) {
    int count = 0;
    if (n < 0)
        n *= -1;
    while (n > 0) {
        if (n % 10 == 7)
            count++;
        n /= 10;
    }
    return count;
}