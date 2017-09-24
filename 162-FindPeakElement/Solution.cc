/**
 * File: /home/jx/Desktop/codes/leetcode/162-FindPeakElement/Solution.cc
 * Project: /home/jx/Desktop/codes/leetcode
 * Created Date: Sunday, September 24th 2017, 7:53:20 pm
 * Author: JX
 * -----
 * Last Modified: Sun Sep 24 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * All shall be well and all shall be well and all manner of things shall be well.
 * We're doomed!
 */

 class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) {
            if (nums[0] > nums[1]) return 0;
            else if (nums[0] < nums[1]) return 1;
        }
        for (int i = 1; i < nums.size()-1; ++i) {
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;            
        }
        if (nums[0] > nums[1]) return 0;
        if (nums[nums.size()-1] > nums[nums.size()-2]) return nums.size()-1;
    }
};