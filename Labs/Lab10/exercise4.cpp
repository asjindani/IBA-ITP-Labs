/*
TASK 4
Print all elements in integer array using pointer
*/

#include <iostream>
using namespace std;

int main() {
    size_t n = 10;
    int numbers[n] {1,2,3,4,5,6,7,8,9,10};
    int* pointer = numbers;

    for (size_t i = 0; i < n; i++)
        cout << *pointer++ << ' ';
    cout << endl;
}