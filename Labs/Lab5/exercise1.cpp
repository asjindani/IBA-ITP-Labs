#include <iostream>
using namespace std;

int main() {
    int n, total{0};

    cout << "Enter number of lines: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << ((i != j) ? " + " : " = ");
        }
        total += i;
        cout << total << endl;
    }
    return 0;
}