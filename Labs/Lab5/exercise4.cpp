#include <iostream>
using namespace std;

int main() {
    int number;

    cout << "Enter n: ";
    cin >> number;
    cout << number << endl;

    int previous = 0;
    bool odd = true;

    for (int i = 10; i <= number*10; i*=10) {
        int digit = number % i / (i/10);
        cout << digit << endl;

        if (digit % 2 == 0) {
            odd = false;
            break;
        }
    }

    cout << boolalpha << odd;

    return 0;
}