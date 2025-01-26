/*
EXERCISE 4
Largest Word
*/

#include <iostream>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    str += " ";

    string word = "";
    string maxWord = "";
    int maxLength = 0;

    for (char c : str) {
        if (isalpha(c))
            word += c;
        else {
            if (word.length() > maxLength) {
                maxLength = word.length();
                maxWord = word;
            }
            word = "";
        }
    }

    cout << maxWord << endl;
}