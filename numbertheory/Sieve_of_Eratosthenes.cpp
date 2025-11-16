// Given an integer n, print all prime numbers ≤ n using the Sieve of Eratosthenes.

#include <iostream>
#include <vector>
using namespace std;

// Sieve of Eratosthenes
vector<int> sieve(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false; // Mark multiples
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++)
        if (isPrime[i]) primes.push_back(i);

    return primes;
}

int main() {
    int n = 50;
    vector<int> primes = sieve(n);

    for (int p : primes) cout << p << " ";
}
