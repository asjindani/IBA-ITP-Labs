/*
TASK 5
Function to swap two integers using pointers
*/

#include <iostream>
using namespace std;

void swap(int* x, int* y);

int main() {
    int a = 10;
    int b = 20;
    swap(a, b);
    cout << a << endl;
    cout << b << endl;
}

void swap(int* x, int* y) {
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}