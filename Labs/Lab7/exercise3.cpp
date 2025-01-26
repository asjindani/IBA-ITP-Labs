/*
EXERCISE 3
Merge Sort

Assume that numbers input are in ascending order.
*/

#include <iostream>
using namespace std;

int main() {
    int n1, n2;

    cout << "Enter size of array 1: ";
    cin >> n1;

    cout << "Enter size of array 2: ";
    cin >> n2;

    cout << endl;

    int arr1[n1], arr2[n2], arr3[n1+n2]{};

    cout << "Input Array 1 Items" << endl;
    for (int i = 0; i < n1; i++) {
        cout << "Enter item " << i+1 << ": ";
        cin >> arr1[i];
    }
    cout << endl;

    cout << "Input Array 2 Items" << endl;
    for (int j = 0; j < n2; j++) {
        cout << "Enter item " << j+1 << ": ";
        cin >> arr2[j];
    }
    cout << endl;

    int i = 0; // array 1 index
    int j = 0; // array 2 index
    int k = 0; // array 3 index

    // Transfer values in sorted order

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr3[k] = arr1[i];
            i++;
        } else {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    
    // Transfer remaining array1 values

    while (i < n1) {
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    // Transfer remaining array 2 values

    while (j < n2) {
        arr3[k] = arr2[j];
        j++;
        k++;
    }

    // Display merged array

    cout << "Merged Array" << endl;
    for (int n : arr3) {
        cout << n << " ";
    }
    cout << endl;
}