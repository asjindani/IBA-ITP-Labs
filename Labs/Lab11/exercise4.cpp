/*
Exercise 4
Remove letter from string using recursion
*/

#include <iostream>
using namespace std;

string removeX(string);

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << removeX(str) << endl;
}

string removeX(string str) {
    if (str.length() == 0)
        return "";
    if (str[0] == 'x')
        return removeX(str.substr(1));
    return str[0] + removeX(str.substr(1));
}