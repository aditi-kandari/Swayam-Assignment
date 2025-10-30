// Solve Tower of Hanoi problem using recursion

#include <iostream>
using namespace std;
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    // Base case: if there's only one disk, move it directly from source to destination
    if (n == 1) {
        cout << "Move disk 1 from rod " << source << " to rod " << destination << endl;
        return;
    }
    // Move n-1 disks from source to auxiliary, using destination as a temporary rod
    towerOfHanoi(n - 1, source, auxiliary, destination);
    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
    // Move the n-1 disks from auxiliary to destination, using source as a temporary rod
    towerOfHanoi(n - 1, auxiliary, destination, source);
    // Time Complexity: O(2^n)
    // Space Complexity: O(n) due to call stack
}
