/*
EXERCISE 1 - SELECTION SORT
- Input numbers from the user
- Use selection sort to sort them
- Ascending order to be implemented
*/

#include <iostream>
#include <array>
using namespace std;

int main() {
    const int n = 10;
    array<int,n> numbers;

    for (int i = 0; i < n; i++) {
        cout << "Enter item " << i+1 << ": ";
        cin >> numbers[i];
    }

    cout << "Unsorted Values: ";
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    // Selection Sort
    for (unsigned int i = 0; i < n-1; i++) {
        for (unsigned int j = i+1; j < n; j++) {
            if (numbers[i] > numbers[j]) {
                numbers[i] = numbers[i] + numbers[j];
                numbers[j] = numbers[i] - numbers[j];
                numbers[i] = numbers[i] - numbers[j];
            }
        }
    }

    cout << "Sorted Values: ";
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;
}