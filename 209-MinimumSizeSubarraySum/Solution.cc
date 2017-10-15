/**
 * File: /home/jx/Desktop/codes/leetcode/209-MinimumSizeSubarraySum/Solution.cc
 * Project: /home/jx/Desktop/codes/leetcode/209-MinimumSizeSubarraySum
 * Created Date: Sunday, October 15th 2017, 10:56:29 pm
 * Author: JX
 * -----
 * Last Modified: Sun Oct 15 2017
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
        int i = 0, j = 0, sum = 0, len = nums.size();
        while(j < nums.size()){
            while(j < nums.size() && sum < s) sum += nums[j++];
            if(i == 0 && sum < s) return 0;
            while(sum - nums[i]>= s) sum -= nums[i++];
            len = min(len, j - i);
            sum -= nums[i++];
        }
        return len;
    }
};