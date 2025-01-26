#include <iostream>
using namespace std;

void permute(string, int);

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    string s = "";

    for (int i = 0; i < number; i++)
        s += 'a' + i;

    permute(s, 0);
    cout << endl;
}

void permute(string str, int index) {
    
    // Base case (no more swaps)
    if (index == str.size() - 1) {
        cout << str + " ";
        return;
    }

    for (int i = index; i < str.size(); i++) {

        // Swapping characters
        swap(str[index], str[i]);

        // Recursive call (next index)
        permute(str, index+1);

        // Backtracing
        swap(str[index], str[i]);
    }
}