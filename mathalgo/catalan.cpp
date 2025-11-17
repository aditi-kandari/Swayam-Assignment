/*
Problem Statement:
Compute the nth Catalan number using Dynamic Programming.
Catalan numbers count many combinatorial structures such as:
- Valid parenthesis sequences
- Unique BSTs
- Ways to triangulate polygons

Formula:
C(n) = Σ C(i)*C(n-i-1), for i = 0..n-1
*/

#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

// nth Catalan number using DP
long long catalan(int n) {
    vector<long long> C(n + 1, 0);
    C[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            C[i] = (C[i] + C[j] * C[i - j - 1]) % MOD;
        }
    }
    return C[n];
}

int main() {
    int n = 10;
    cout << "Catalan(" << n << ") = " << catalan(n);
}
