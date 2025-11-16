// Solve the system of congruences:
// x = a[i](mod n[i])
// for arrays a[] and n[], and return the smallest non-negative solution.

#include <iostream>
#include <vector>
using namespace std;

// Extended Euclid: ax + by = gcd(a,b)
long long ext_gcd(long long a, long long b, long long &x, long long &y) {
    if (!b) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

// Chinese Remainder Theorem
long long CRT(vector<long long> a, vector<long long> n) {
    long long x = a[0], m = n[0];

    for (int i = 1; i < a.size(); i++) {
        long long x1, y1;
        long long g = ext_gcd(m, n[i], x1, y1);

        if ((a[i] - x) % g != 0) return -1; // No solution

        long long lcm = m / g * n[i];

        long long tmp = ((a[i] - x) / g % (n[i] / g) * x1 % (n[i] / g));
        x = (x + m * tmp) % lcm;
        if (x < 0) x += lcm;

        m = lcm; // updated modulus
    }
    return x;
}

int main() {
    vector<long long> a = {2, 3, 2};
    vector<long long> n = {3, 5, 7};

    cout << "Solution: " << CRT(a, n);  // Output: 23
}
