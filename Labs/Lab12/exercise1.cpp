/*
EXERCISE 1
Password Validator
*/

#include <iostream>
using namespace std;

bool isValid(string);

int main() {
    string password;
    cout << "Enter a password: ";
    getline(cin, password);
    cout << "Password is " << (isValid(password) ? "" : "not ") << "valid." << endl;
}

bool isValid(string password) {
    if (password.length() < 10)
        return false;

    int countLetter = 0;
    int countDigit = 0;
    for (char character : password) {
        if (isalpha(character))
            countLetter++;
        else if (isdigit(character))
            countDigit++;
    }

    return (countLetter + countDigit == password.length() && countDigit >= 2 && countLetter >= 1);
}