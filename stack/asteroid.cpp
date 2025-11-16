// Solve the asteroid collision problem using a stack-based approach

#include <iostream>
#include <vector>
using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> stack; // Using vector as a stack to store surviving asteroids

    for (int asteroid : asteroids) {
        bool destroyed = false; // Flag to check if the current asteroid is destroyed

        // Process collisions only if the current asteroid is moving left
        while (!stack.empty() && asteroid < 0 && stack.back() > 0) {
            int top = stack.back();
            // Compare sizes of colliding asteroids
            if (top < -asteroid) {
                stack.pop_back(); // Top asteroid is smaller, it gets destroyed
            } else if (top == -asteroid) {
                stack.pop_back(); // Both asteroids are equal, both get destroyed
                destroyed = true; // Current asteroid is also destroyed
                break;
            } else {
                destroyed = true; // Current asteroid is smaller, it gets destroyed
                break;
            }
        }
        // If the current asteroid is not destroyed, add it to the stack
        if (!destroyed) {
            stack.push_back(asteroid);
        }
    }
    return stack; // Return the surviving asteroids
} // Time Complexity: O(n), Space Complexity: O(n)
