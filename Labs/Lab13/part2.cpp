/*
Part 2: Exercise 7-11
Data Type for Fractions
*/

#include <iostream>
#include <numeric>
using namespace std;

struct fraction {
    int num;
    int denom;
};

int gcf(int a, int b);

ostream& operator<<(ostream& os, const fraction& f);
fraction simplify(const fraction& f);
fraction operator+(const fraction& f1, const fraction& f2);
void operator+=(fraction& f1, const fraction& f2);
fraction operator*(const fraction& f1, const fraction& f2);
void operator*=(fraction& f1, const fraction& f2);
bool operator==(const fraction& f1, const fraction& f2);

int main() {
    fraction f1 {1, 2};
    cout << f1 << endl; // prints 1/2

    fraction f2 {3, 4}; f2 += f1;
    cout << f2 << endl; // should prints 5/4

    fraction f3 = f1 * f2;
    cout << f3 << endl; // should prints 5/8

    fraction f4 {1, 3}; f3 *= (f1 * f2);
    cout << f3 << endl; // should prints 25/64

    fraction f5 {2, 4}; // same as f1
    if (f1 == f5)
    cout << "f1 and f5 are equal" << endl;
    else
    
    cout << "f1 and f5 are not equal" << endl;
    // the above should print "f1 and f5 are equal"
}

int gcf(int a, int b) {
    if (a == 0)
        return b;
    return gcf(b % a, a);
}

ostream& operator<<(ostream& os, const fraction& f) {
    os << f.num << "/" << f.denom;
    return os;
}

fraction simplify(const fraction& f) {
    int factor = gcd(f.num, f.denom);
    return {f.num/factor, f.denom/factor};
}

fraction operator+(const fraction& f1, const fraction& f2) {
    fraction f{f1.num*f2.denom+f2.num*f1.denom, f1.denom*f2.denom};
    return simplify(f);
}

void operator+=(fraction& f1, const fraction& f2) {
    f1 = f1 + f2;
}

fraction operator*(const fraction& f1, const fraction& f2) {
    fraction f {f1.num*f2.num, f1.denom*f2.denom};
    return simplify(f);
}

void operator*=(fraction& f1, const fraction& f2) {
    f1 = f1 * f2;
}

bool operator==(const fraction& f1, const fraction& f2) {
    fraction f3 = simplify(f1);
    fraction f4 = simplify(f2);
    return (f3.num == f4.num) && (f3.denom == f4.denom);
}