/*
EXERCISE 2
Bubble Sort
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Enter number of items: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter item " << i+1 << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-1-i; j++)
            if (arr[j] > arr[j+1]) {
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }

    for (int item : arr) {
        cout << item << " ";
    }
    cout << endl;
}