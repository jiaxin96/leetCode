/**
 * File: /home/jx/Desktop/codes/leetcode/53-MaximumSubarray/Solution.cc
 * Project: /home/jx/Desktop/codes/leetcode
 * Created Date: Saturday, September 23rd 2017, 6:45:28 pm
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
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curSum = nums[0];
        int curBegin = 0, leftIndex = 0, rightIndex = 0;
        for (int i = 1; i < nums.size(); ++i) {
            curSum += nums[i];
            if (curSum < nums[i]) {
                curSum = nums[i];
                curBegin = i;
            }
            if (curSum > maxSum) {
                maxSum = curSum;
                leftIndex = curBegin;
                rightIndex = i;
            }
        }
        return maxSum;
    }
};