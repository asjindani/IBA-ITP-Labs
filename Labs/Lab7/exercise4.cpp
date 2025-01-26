/*
EXERCISE 4
Insertion Sort
*/

#include <iostream>
using namespace std;

int main() {
    const int n = 20;
    int numbers[n] = {};
    int inserted;

    int n2;

    cout << "Enter the number of elements <= 20" << endl;
    cin >> n2;
    cout << endl;

    if (n2 == 20) {
        cout << "Insertion of new element not possible" << endl;
        return 0;
    }

    if (n2 > 20 || n2 < 0) {
        cout << "The number must be between 0 and 20" << endl;
        return 0;
    }

    cout << "Enter " << n2 << " elements in ascending order" << endl;
    for (int i = 0; i < n2; i++) {
        cin >> numbers[i];
    }
    cout << endl;

    cout << "Enter the number to be inserted : ";
    cin >> inserted;
    cout << endl;

    int i = n2;
    while (i > 0 && inserted < numbers[i-1]) {
        numbers[i] = numbers[i-1];
        i--;
    }
    numbers[i] = inserted;

    cout << "Array after insertion is" << endl << endl;

    for (int j = 0; j < n2+1; j++)
        cout << numbers[j] << " ";
    cout << endl;
}