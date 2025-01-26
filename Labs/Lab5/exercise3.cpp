#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string hex;
    int base = 16;

    // cout << "Enter the number base: ";
    // cin >> base;

    cout << "Enter number: ";
    cin >> hex;

    int n = hex.length();

    int total = 0;

    for (int i = 0; i < n; i++) {
        int number = 0;

        if (hex[i] >= '0' && hex[i] <= '9') {
            number = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            number = hex[i] - 'A' + 10;
        }

        // cout << number << " " << pow(base, n-i-1) << endl;
        total += number * pow(base, n-i-1);
    }

    cout << total << endl;

    return 0;
}