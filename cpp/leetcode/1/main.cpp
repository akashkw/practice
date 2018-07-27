
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// Time:  O()
// Space: O()

// Given an array of integers, return indices of the two numbers
// such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution.
//
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        return vector<int>({0, 1});
    }
};

int main() {
    cout << "1. Two Sum" << endl;
    vector<int> num = {2, 7, 11, 15};
    int target = 9;
    for (auto x : Solution::twoSum(num, target)) {
        cout << x << " ";
    }
    cout << endl;
}
