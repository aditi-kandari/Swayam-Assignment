// Print all the subsets of an array.

#include <iostream>
#include <vector>
using namespace std;

// Function to generate all the subsets of an array.

void generate(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans) {
    if (index == nums.size()) {
        ans.push_back(current);
        return;
    }

    // include current element
    current.push_back(nums[index]);
    generate(index + 1, nums, current, ans);

    // exclude current element
    current.pop_back();
    generate(index + 1, nums, current, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> current;
    generate(0, nums, current, ans); // time complexity O(2^n);
    return ans;
}