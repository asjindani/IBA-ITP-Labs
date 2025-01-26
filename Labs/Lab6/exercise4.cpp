/*
EXERCISE 4
- Randomly generate 100 lowercase letters
- Store the letters in an array of characters
- Display the occurance of each of the letters
*/

#include <iostream>
#include <ctime>
#include <array>
using namespace std;

int main() {
    srand(time(0));

    const int n = 100;
    array<char,n> characters;
    array<int,26> counts;

    // Initialize counts to 0
    for (int& count : counts)
        count = 0;

    // Generate and display random characters
    cout << "Random characters: ";
    for (int i = 0; i < n; i++) {
        int number = rand() % 26;
        counts[number] += 1;
        char character = char(number+'a');
        characters[i] = character;
        cout << character << " ";
    }
    cout << endl;

    // Display all character counts
    cout << "Character counts: ";
    for (int i = 0; i < 26; i++) {
        char character = char(i+'a');
        cout << character << "=" << counts[i] << " ";
    }
    cout << endl;
}