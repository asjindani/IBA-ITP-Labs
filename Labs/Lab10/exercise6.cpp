/*
TASK 6
Function to take array, size, threshold and count elements greater than threshold
*/

#include <iostream>
using namespace std;

int countGreaterThan(int* arr, size_t size, int threshold);

int main() {
    int size = 5;
    int arr[size] {4,10,20,50,100};
    cout << countGreaterThan(arr, size, 9) << endl;
}

int countGreaterThan(int* arr, size_t size, int threshold) {
    int count = 0;
    for (size_t i = 0; i < size; i++)
        if (arr[i] > threshold)
            count++;
    return count;
}