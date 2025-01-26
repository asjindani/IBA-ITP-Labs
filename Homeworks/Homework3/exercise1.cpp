#include <iostream>
#include <vector>
using namespace std;

vector<string> split(string str, const string& delimeter) {
    size_t pos;
    vector<string> tokens;

    while ((pos = str.find(delimeter)) != string::npos) {
        tokens.push_back(str.substr(0, pos));
        str = str.substr(pos + delimeter.length());
    }
    tokens.push_back(str);
    
    return tokens;
}

bool isInteger(string str) {
    for (char chr : str)
        if (!isdigit(chr))
            return false;
    return true;
}

int main() {
    string text, team;
    // cout << "Enter games summary: ";
    // getline(cin, text);
    text = "Barca 1 Sevilla 0, Real Madrid 1 Barca 1, Barca 3 Valencia 1, Villarreal 2 Barca 1, Espanyol 2 Barca 4";

    cout << "Enter team name: ";
    cin >> team;
    cout << endl;

    int wins = 0,
        draws = 0,
        defeats = 0,
        total_score = 0,
        total_conceded = 0,
        home = 0,
        points;

    for (string s : split(text, ", ")) {
        vector<string> v = split(s, " ");

        // Combine team1 name words
        while (!isInteger(v[1])) {
            v[0] += ' ' + v[1];
            v.erase(v.begin() + 1);
        }

        // Combine team2 name words
        while (!isInteger(v[3])) {
            v[2] += ' ' + v[3];
            v.erase(v.begin() + 3);
        }

        cout << v[0] << ": " << v[1] << " | " << v[2] << ": " << v[3] << endl;
        if (team != v[0] && team != v[2])
            continue;
        int score, oppscore;
        if (team == v[0]) {
            score = stoi(v[1]);
            oppscore = stoi(v[3]);
            home++;
        } else {
            score = stoi(v[3]);
            oppscore = stoi(v[1]);
        }

        if (score > oppscore)
            wins++;
        else if (score < oppscore)
            defeats++;
        else draws++;

        total_score += score;
        total_conceded += oppscore;
    }
    points = wins*3 + draws;
    cout << "number of wins = " << wins << endl;
    cout << "number of draws = " << draws << endl;
    cout << "number of defeats = " << defeats << endl;
    cout << "goals scored = " << total_score << endl;
    cout << "goals conceded = " << total_conceded << endl;
    cout << "number of points = " << points << endl;
    cout << "home matches = " << home << endl;
}

