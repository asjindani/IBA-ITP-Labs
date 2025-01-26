#include <iostream>
using namespace std;

void text(int number) {
    switch (number) {
        case 0: cout << "zero"; break;
        case 1: cout << "one "; break;
        case 2: cout << "two "; break;
        case 3: cout << "three "; break;
        case 4: cout << "four "; break;
        case 5: cout << "five "; break;
        case 6: cout << "six "; break;
        case 7: cout << "seven "; break;
        case 8: cout << "eight "; break;
        case 9: cout << "nine "; break;
        case 10: cout << "ten "; break;
        case 11: cout << "eleven "; break;
        case 12: cout << "twelve "; break;
        case 13: cout << "thirteen "; break;
        case 14: cout << "fourteen "; break;
        case 15: cout << "fifteen "; break;
        case 16: cout << "sixteen "; break;
        case 17: cout << "seventeen "; break;
        case 18: cout << "eighteen "; break;
        case 19: cout << "nineteen "; break;
        case 20: cout << "twenty "; break;
        case 30: cout << "thirty "; break;
        case 40: cout << "forty " ; break;
        case 50: cout << "fifty " ; break;
        case 60: cout << "sixty " ; break;
        case 70: cout << "seventy "; break;
        case 80: cout << "eighty "; break;
        case 90: cout << "ninety "; break;
    }
}

int num999(int x) {
    if (x == 0) {
        text(x);
        return 0;
    }

    // Displays number between 1 and 999 as text
    int ones, tens, hundreds;

    ones = x % 10;
    tens = x % 100 / 10;
    hundreds = x / 100;

    if (hundreds > 0) {
        text(hundreds);
        cout << "hundred ";
    }

    if (tens == 1) {
        text(x % 100);
    } else {
        if (tens > 0)
            text(tens*10);
        if (ones > 0)
            text(ones);
    }
    return 0;
}

int main() {
    int number, thousands;

    cout << "Enter a number: ";
    cin >> number;

    if (number < 0) {
        cout << "negative ";
        number = -number;
    }

    thousands = number / 1000;

    if (thousands > 0) {
        num999(thousands);
        cout << "thousand ";
    }

    if (thousands == 0 || number % 1000 != 0)
        num999(number % 1000);

    cout << endl;

    return 0;
}