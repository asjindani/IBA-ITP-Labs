/* EXERCISE 5 */

#include <iostream>
using namespace std;

bool isalphanum(string);

int main() {
    string text;
    cout << "Enter some text: ";
    getline(cin, text);

    string word = "";
    for (int i = 0; i < text.length(); i++) {
        char x = text[i];
        if (x == ' ' || i == text.length()-1) {
            if (i == text.length()-1)
                word += x;

            if (isalphanum(word))
                cout << word << ' ';
            word = "";
        } else {
            word += x;
        }
    }
    cout << endl;
}

bool isalphanum(string str) {
    int alpha = 0;
    int num = 0;
    bool isalpha = false;
    bool isnum = false;
    for (int i = 0; i < str.length(); i++) {
        char x = str[i];
        if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z')) {
            isalpha = true;
            alpha++;
        }
        else if (x >= '0' && x <= '9') {
            isnum = true;
            num++;
        }
    }
    return (alpha + num == str.length()) && isalpha && isnum;
}