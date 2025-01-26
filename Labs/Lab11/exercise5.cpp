/*
Exercise 5
Output pattern using recursion
*/

#include <iostream>
using namespace std;

void writeChars(int);

int main() {
    for (int i = 1; i <= 8; i++) {
        cout << "writeChars(" << i << "): ";
        writeChars(i);
        cout << endl;
    }
}

void writeChars(int n) {
    if (n < 1)
        return;
    if (n == 1)
        cout << "*";
    else if (n == 2)
        cout << "**";
    else {
        cout << "<";
        writeChars(n-2);
        cout << ">";
    }
}