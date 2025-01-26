/*
Exercise 2
Fibonacii sequence terms using recursion
*/

#include <iostream>
using namespace std;

int fibonacii(unsigned int);

int main() {
    for (int i = 1; i <= 10; i++)
        cout << fibonacii(i) << ' ';
    cout << endl;
}

int fibonacii(unsigned int n) {
    if (n == 0) // invalid n
        return 0;
    if (n < 3)
        return n-1;
    return fibonacii(n-1) + fibonacii(n-2);
}