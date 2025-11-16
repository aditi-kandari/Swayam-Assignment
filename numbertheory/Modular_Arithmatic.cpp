// Implement basic modular arithmetic operations:

// Addition
// Subtraction
// Multiplication
// Modular Inverse (using Fermat’s theorem, mod must be prime)

#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

// Fast exponentiation: a^b % MOD
long long modpow(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return r;
}

// modular inverse using Fermat (MOD must be prime)
long long modinv(long long a) {
    return modpow(a, MOD - 2);
}

int main() {
    long long a = 10, b = 3;

    cout << "Add: " << (a + b) % MOD << "\n";
    cout << "Sub: " << (a - b + MOD) % MOD << "\n";
    cout << "Mul: " << (a * b) % MOD << "\n";
    cout << "Inv of 3: " << modinv(3) << "\n";
}
