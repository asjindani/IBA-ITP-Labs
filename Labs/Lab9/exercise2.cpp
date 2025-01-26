/* EXERCISE 2 */

#include <iostream>
using namespace std;

int str_to_int(string);

int main() {
    string str;
    cout << "Enter a number: ";
    cin >> str;
    cout << "String to integer result: " << str_to_int(str) << endl;
}

int str_to_int(string str) {
    bool negative = false;
    int index = 0;
    int number = 0;
    bool leadingZeros = true;

    if (str[0] == '+')
        index++;

    if (str[0] == '-') {
        negative = true;
        index++;
    }

    while (index < str.length()) {
        char character = str[index];
        if (character >= '0' && character <= '9') {
            if (character > '0')
                leadingZeros = false;
            if (!leadingZeros) {
                number += character - '0';
                number *= 10;
            }
        } else {
            cout << "Error: non-alphanumeric characters found." << endl;
            return 0;
        }
        index++;
    }
    number /= 10;

    if (negative)
        number *= -1;

    return number;
}