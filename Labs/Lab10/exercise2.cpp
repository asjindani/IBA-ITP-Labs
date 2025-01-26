/*
TASK 2
Copy one string to another using pointer
*/

#include <iostream>
using namespace std;

int main() {
    size_t n = 100;
    
    char string1[n]{};
    char string2[n]{};

    char * string1Ptr = string1;
    char * string2Ptr = string2;

    cout << "Enter any string (less than " << n << " characters): ";
    cin.getline(string1, n);

    while (*(string1Ptr) != '\0')
        *(string2Ptr++) = *(string1Ptr++);
    // *(string2Ptr) = '\0';

    cout << "String 1: " << string1 << endl;
    cout << "String 2: " << string2 << endl;
}