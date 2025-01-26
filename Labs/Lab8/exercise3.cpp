/*
EXERCISE 3
Character Count
*/

#include <iostream>
using namespace std;

int charactercheck(string, char);

int main() {
    string text;
    char character;
    int count;

    cout << "Enter some text: ";
    getline(cin, text); // to capture entire line instead of a single word

    cout << "Enter a character: ";
    cin >> character;

    count = charactercheck(text, character);

    cout << "The character '" << character << "' appeared " << count << " times in the text" << endl;
}

int charactercheck(string s, char c) {
    int count = 0;
    for (size_t i = 0; i < s.length(); i++)
        if (s[i] == c)
            count += 1;
    return count;
}