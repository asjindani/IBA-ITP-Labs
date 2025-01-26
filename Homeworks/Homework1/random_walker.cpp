// Hypothesis: the mean square distance grows linearly with n.
// As a function, the relationship between them would be f(n) = n.
// Since at trials = 100000, the mean square distance is approximately n.

#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int n, x, y, distance;

    srand(time(0));

    cout << "Enter n: ";
    cin >> n;

    x = 0;
    y = 0;

    cout << "(0, 0)" << endl;

    for (int i = 0; i < n; i++) {
        int move = rand() % 4;
        switch (move) {
            case 0: x++; break; // north
            case 1: x--; break; // south
            case 2: y++; break; // east
            case 3: y--; break; // west
        }
        cout << "(" << x << ", " << y << ")" << endl;
    }

    distance = x*x + y*y;

    cout << "squared distance = " << distance;
}