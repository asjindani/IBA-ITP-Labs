/*
EXERCISE 2
Anagram Checker
*/

#include <cctype>
#include <iostream>
#include <algorithm>
using namespace std;

bool isAnagram(string, string);

int main() {
    string string1, string2;
    cout << "Enter string 1: ";
    getline(cin, string1);
    cout << "Enter string 2: ";
    getline(cin, string2);
    cout << "The strings are " << (isAnagram(string1, string2) ? "" : "not ") << "anagrams." << endl;
}

bool isAnagram(string string1, string string2) {
    // Remove space characters
    string1.erase(remove(string1.begin(), string1.end(), ' '), string1.end());
    string2.erase(remove(string2.begin(), string2.end(), ' '), string2.end());

    // Convert to uppercase
    transform(string1.begin(), string1.end(), string1.begin(), ::toupper);
    transform(string2.begin(), string2.end(), string2.begin(), ::toupper);

    // Sort in alphabetical order
    sort(string1.begin(), string1.end());
    sort(string2.begin(), string2.end());

    return string1 == string2;
}