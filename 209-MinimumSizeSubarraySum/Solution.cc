/**
 * File: /home/jx/Desktop/codes/leetcode/209-MinimumSizeSubarraySum/Solution.cc
 * Project: /home/jx/Desktop/codes/leetcode/209-MinimumSizeSubarraySum
 * Created Date: Sunday, October 15th 2017, 10:56:29 pm
 * Author: JX
 * -----
 * Last Modified: Mon Oct 16 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * All shall be well and all shall be well and all manner of things shall be well.
 * We're doomed!
 */

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0, len = INT_MAX, sum = 0;
        while(j < nums.size()){
            sum += nums[j++];
            while(sum >= s){
                len = min(len, j - i);
                sum -= nums[i++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};