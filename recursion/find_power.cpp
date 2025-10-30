// find the value of n raised to the power of its own reverse using recursion

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int power(int y,int a){
      if(a==0) return 1;
      return y*power(y,a-1);
      // Time Complexity: O(a)
}
    
int reverseExponentiation(int n) {
    int y=n;
    string s=to_string(n);
    reverse(s.begin(),s.end());
    int a = stoi(s);
    int z = power(y,a);
    return z;
    // Time Complexity: O(d) where d is the number of digits in n (for reversing)
}