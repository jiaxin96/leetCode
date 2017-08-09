/**
 * File: e:\code\leetCode\46-Permutations\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Wednesday, August 9th 2017, 8:10:33 pm
 * Author: JX
 * -----
 * Last Modified: Wed Aug 09 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

class Solution {
public:

    void swap(vector<int> & nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    void per(vector<int> & nums, int b, int len, vector<vector<int>> & ans) {
        if (b == len-1) {
            // vector<int> t(len, 0);
            // for (int i = 0 ; i < len; i++) {
            //     t[i] = nums[i];
            // }
            ans.push_back(nums);
        } else {
            for (int i = b; i < len; ++i) {
                swap(nums, i, b);
                per(nums, b + 1, len, ans);
                swap(nums, i, b);                
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        per(nums, 0, nums.length(), ans);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
