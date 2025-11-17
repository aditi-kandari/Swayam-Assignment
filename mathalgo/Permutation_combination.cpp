/*
Problem Statement:
Implement functions to compute:
1. nCr (Combination)
2. nPr (Permutation)
All results must be modulo 1e9+7.
*/

#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

// fast exponentiation
long long modpow(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return r;
}

// modular inverse
long long modinv(long long x) {
    return modpow(x, MOD - 2);
}

int main() {
    int n = 10, r = 3;

    vector<long long> fact(n + 1, 1);
    for (int i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % MOD;

    long long nPr = fact[n] * modinv(fact[n - r]) % MOD;
    long long nCr = fact[n] * modinv((fact[r] * fact[n - r]) % MOD) % MOD;

    cout << "nPr = " << nPr << "\n";
    cout << "nCr = " << nCr << "\n";
}
