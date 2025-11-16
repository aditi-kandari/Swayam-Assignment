// Given integers a, b, and mod, compute a^b mod mod :

#include <iostream>
using namespace std;

// Binary exponentiation
long long modexp(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod; // Multiply when bit is 1
        a = (a * a) % mod;                // Square base
        b >>= 1;                          // Shift right
    }
    return res;
}

int main() {
    cout << modexp(5, 117, 1000000007);
}
