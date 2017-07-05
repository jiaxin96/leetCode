/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      std::vector<int> ans;
        for (int i = 0; i < nums.size() - 1; ++i) {

          for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
              ans.push_back(i);
              ans.push_back(j);
              return ans;
            }
          }
        }

    return ans;
    }
};

// int main(int argc, char const *argv[]) {
//   std::vector<int> v;
//   int target;
//   return 0;
// }
