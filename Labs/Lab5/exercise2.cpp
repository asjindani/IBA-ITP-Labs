#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;

    cout << "Enter number: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n-i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        for (int j = i - 1; j > 0; j--) {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}