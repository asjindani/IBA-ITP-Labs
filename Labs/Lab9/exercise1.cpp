/* EXERCISE 1 */

#include <iostream>
#include <cmath>
using namespace std;

bool isDudeney(int);

int main() {
    for (int i = 0; i < 200000; i++)
        if (isDudeney(i))
            cout << i << " ";
    cout << endl;
}

bool isDudeney(int number) {
    double sum = 0;
    double root = cbrt(number);
    if (number < 0)
        number *= -1;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return root == sum;
}