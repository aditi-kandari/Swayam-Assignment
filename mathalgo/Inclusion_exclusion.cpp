/*
Problem Statement:
Given integers n and a list of divisors d[],
count how many numbers from 1 to n are divisible by at least one d[i]
using the Inclusion–Exclusion Principle.
*/

#include <iostream>
#include <vector>
using namespace std;

// lcm using gcd
long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

// inclusion–exclusion for count of divisible numbers
long long inclusion_exclusion(long long n, const vector<long long>& d) {
    int k = d.size();
    long long ans = 0;

    for (int mask = 1; mask < (1 << k); mask++) {
        long long curr_lcm = 1;
        int bits = __builtin_popcount(mask);

        for (int i = 0; i < k; i++) {
            if (mask & (1 << i))
                curr_lcm = lcm(curr_lcm, d[i]);
        }

        if (bits % 2 == 1) ans += n / curr_lcm;  // add odd subsets
        else ans -= n / curr_lcm;               // subtract even subsets
    }
    return ans;
}

int main() {
    long long n = 100;
    vector<long long> d = {2, 3, 5};

    cout << "Count = " << inclusion_exclusion(n, d);
}
