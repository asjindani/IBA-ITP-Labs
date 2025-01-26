/*
EXERCISE 5
- Generate 30 random numbers
- Display the grade distribution
*/

#include <iostream>
#include <array>
#include <iomanip>
#include <ctime>
using namespace std;

int main() {
    const int n = 30;
    array<int,n> grades{};
    array<int,11> counts{};

    srand(time(0));
    
    // Generate, display, and count random grades
    cout << "Grades: ";
    for (int& grade : grades) {
        grade = rand() % 101;
        cout << grade << " ";
        counts[grade/10] += 1;
    }
    cout << endl;
    
    cout << "Grade distribution:" << endl;

    for (int i = 0; i <= 100; i += 10) {
        if (i == 0)
            cout << "  0-9: ";
        else if (i == 100)
            cout << "  100: ";
        else
            cout << i << "-" << i+9 << ": ";

        unsigned int frequency = counts[i/10];
        
        for (unsigned int j = 0; j < frequency; j++)
            cout << "*";
        cout << endl;
    }
}