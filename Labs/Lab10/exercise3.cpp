/*
TASK 3
Count vowels in string using pointer
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

    while (*strPtr != '\0') {
        char c = *strPtr;

        // Convert to lowercase if uppercase
        if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';

        // Check lowercase vowels and count
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;

        strPtr++;
    }

    cout << "Count of vowels in " << str << " is " << count << endl;
}