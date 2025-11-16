// Find all the permutations of the string.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to print all permutations of string.
void permute(string &s, int l, int n) {
    if (l == n-1) {
        cout << s;
        return;
    }

    for (int i = l; i <n; i++) {
        swap(s[l], s[i]);          // swap current index with i
        permute(s, l + 1, n); // recurse for next index
        swap(s[l], s[i]);          // backtrack (undo swap)
    }
}

int main(){
    string s="ABC";
    permute(s,0,s.length());
}