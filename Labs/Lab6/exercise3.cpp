/*
EXERCISE 3
- Accept an array of integers as input
- Return the percentage of even numbers

Test cases
- For {6,2,9,11,3} return 40.0
- For no even inputs return 0.0
*/

#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

int main() {
    const int n = 10;
    array<int,n> numbers;
    unsigned int even = 0;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i+1 << ": ";
        cin >> numbers[i];

        if (numbers[i] % 2 == 0) {
            even += 1;
        }
    }

    cout << setprecision(1) << fixed;
    cout << "Percentage of even values: " << static_cast<double>(even) / n * 100 << endl;
}