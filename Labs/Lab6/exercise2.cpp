/*
EXERCISE 2
- Input an integer from the user
- Display the even digits only
*/

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    int place = 1;
    int result = 0;

    if (n < 0) {
        place = -1;
        n = -n;
    }

    while (n > 0) {
        int digit = n % 10;

        if (digit % 2 == 0) {
            result += digit * place;
            place *= 10;
        }

        n /= 10;
    }

    cout << result << endl;
}