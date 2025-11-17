/*
Problem Statement:
Given an integer n, compute Euler’s Totient Function φ(n),
which counts the number of integers 1 ≤ k ≤ n such that gcd(k, n) = 1.
*/

#include <iostream>
using namespace std;

// Euler Totient in O(sqrt(n))
long long phi(long long n) {
    long long result = n;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;  // remove all factors of p
            result -= result / p;      // apply formula
        }
    }
    if (n > 1) result -= result / n;   // remaining prime
    return result;
}

int main() {
    long long n = 36;
    cout << "phi(" << n << ") = " << phi(n);
}
