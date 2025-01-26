/*
EXERCISE 5
Subsequence
*/

#include <iostream>
using namespace std;

int main() {
    string str;
    string substr;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Enter a substring: ";
    getline(cin, substr);

    cout << "Is subse1 is the subsequence of word1? ";

    size_t i = 0, j = 0;

    while (j < substr.length()) {
        if (str[i] == substr[j])
            j++;
        else
            i++;
        if (i >= str.length()) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}