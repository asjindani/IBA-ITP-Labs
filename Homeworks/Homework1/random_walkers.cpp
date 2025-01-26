#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int n, trials;
    double distance = 0;

    srand(time(0));

    cout << "Enter n and trials: ";

    cin >> n >> trials;

    for (int i = 0; i < trials; i++) {
        int x = 0, y = 0;
        for (int j = 0; j < n; j++) {
            switch (rand() % 4) {
                case 0: x++; break;
                case 1: x--; break;
                case 2: y++; break;
                case 3: y--; break;
            }
        }
        distance += x*x + y*y;
    }

    cout << "mean squared distance = " << distance / trials << endl;

    return 0;
}