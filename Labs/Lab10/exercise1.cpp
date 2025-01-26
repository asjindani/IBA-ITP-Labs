/*
TASK 1
Length of string using pointer
*/

#include <iostream>
using namespace std;

int main() {
    size_t n = 100;
    char str[n];
    char * strPtr = str;
    int count = 0;

    cout << "Enter any string (less than " << n << " characters): ";
    cin.getline(str, n);

    while (*(strPtr++) != '\0')
        count++;

    cout << "Length of " << str << " is " << count << endl;
}