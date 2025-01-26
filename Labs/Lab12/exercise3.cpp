/*
EXERCISE 3
*/

#include <iostream>
#include <algorithm>
using namespace std;

int countSubstring(string, string);
int countWords(string);
int countSentences(string);
int countWord(string, string);

int main() {
    string str;
    string option;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "\n1. Find/Replace\n2. Words\n3. Sentences\n4. Articles\n5. Spaces\n\n";
    cout << "Select an option from above (1-6): ";

    getline(cin, option);

    switch (option[0]-'0') {
        case 1: {
            string toFind;
            cout << "Enter a substring to find: ";
            getline(cin, toFind);
            size_t position;
            position = str.find(toFind);
            if (position != string::npos) {
                string toReplace;
                cout << "Substring found starting at index " << position << "." << endl;
                cout << "Enter a substring to replace with: ";
                getline(cin, toReplace);
                str.replace(position, toFind.length(), toReplace);
                cout << "Updated string: \"" << str << "\"" << endl;
            }
            else
                cout << "Substring not found." << endl;
            break;
        }

        case 2:
            cout << "Number of words is " << countWords(str) << endl;
            break;

        case 3:
            cout << "Number of sentences is " << countSentences(str) << endl;
            break;

        case 4:
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            cout << "Count of \"a\" in string is " << countWord("a", str) << endl;
            cout << "Count of \"an\" in string is " << countWord("an", str) << endl;
            cout << "Count of \"the\" in string is " << countWord("the", str) << endl;
            break;

        case 5:
            cout << "Number of spaces is " << countSubstring(" ", str) << endl;
            break;

        default:
            cout << "Invalid option selected." << endl;
    }
}

int countSubstring(string substr, string str) {
    int count = 0;
    int position = str.find(substr);
    while (position != string::npos) {
        position = str.find(substr, position+1);
        count++;
    }
    return count;
}

int countSentences(string str) {
    str += ". ";
    int count = 0;
    string sentence = "";
    bool flag = false;

    // check for ". " for next sentence
    for (char c : str) {
        if (c != '.') {
            if (flag) {
                if (c == ' ') {
                    if (countWords(sentence))
                        count++;
                    sentence = "";
                } else
                    sentence += c;
                flag = false;
            } else
                sentence += c;
        } else {
            flag = true;
        }
    }
    return count;

    // str.erase(str.find_last_not_of(' ')+1); // remove ending spaces
    // return countSubstring(". ", str) - !str.find_first_of(". ") + 1;
}

int countWords(string str) {
    str += " ";
    int count = 0;
    string word = "";

    for (char c : str) {
        if (isalpha(c)) {
            word += c;
        } else if (c == ' ') {
            if (word.length() > 0)
                count++;
            word = "";
        }
    }

    return count;

    // str.erase(0, str.find_first_not_of(' ')); // remove starting spaces
    // str.erase(str.find_last_not_of(' ')+1); // remove ending spaces

    // get rid of double spaces
    // size_t position = str.find("  ");
    // while (position != string::npos) {
    //     str.replace(position, 2, " ");
    //     position = str.find("  ");
    // }

    // cout << endl << "\"" << str << "\"" << endl;

    // return countSubstring(" ", str) + 1;
}

int countWord(string word, string str) {
    int count = 0;
    if (!str.find_first_of(word) && !isalpha(str[word.length()]))
        count++;
    int position = str.find(' ' + word);
    while (position != string::npos) {
        if (position+word.length()+1 >= str.length() || !isalpha(str[position+word.length()+1]))
            count++;
        position = str.find(' ' + word, position+1);
    }
    return count;
}