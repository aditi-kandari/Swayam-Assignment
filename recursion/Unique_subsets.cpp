// Find All the unique subsets of an array.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find all the unique subsets(without using set data structure):

void generate(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans) {
    ans.push_back(current);

    for (int i = index; i < nums.size(); i++) {
        // Skip duplicates at the same recursion level
        if (i > index && nums[i] == nums[i - 1])
            continue;

        current.push_back(nums[i]);
        generate(i + 1, nums, current, ans);
        current.pop_back(); // backtrack
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // sort to group duplicates
    vector<vector<int>> ans;
    vector<int> current;
    generate(0, nums, current, ans);
    return ans;
}