/* EXERCISE 3 */

#include <iostream>
using namespace std;

string tobinary(int, int);

int main() {
    int number;
    
    cout << "Enter a number between 0 and 511: ";
    cin >> number;

    if (number > 511 || number < 0) {
        cout << "Input was out of range." << endl;
        return 0;
    }

    string binary = tobinary(number, 9);

    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (binary[k] == '0')
                cout << "H ";
            else
                cout << "T ";
            k++;
        }
        cout << endl;
    }

}

string tobinary(int number, int bits=9) {
    string binary = "";
    for (int i = 0; i < bits; i++) {
        binary = char(number % 2 + '0') + binary;
        number /= 2;
    }
    return binary;
}