/* EXERCISE 4 */

#include <iostream>
using namespace std;

int CenteredAverage(int[], int);

int main() {
    int arr[] = {5, 2, 3, 4, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << CenteredAverage(arr, size) << endl;
}

int CenteredAverage(int arr[], int size) {
    int min = arr[0];
    int max = arr[0];
    int total = arr[0];

    for (int i = 1; i < size; i++) {
        total += arr[i];

        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    return (total - min - max) / (size - 2);
}