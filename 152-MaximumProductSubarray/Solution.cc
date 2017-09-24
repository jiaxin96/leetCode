/**
 * File: /home/jx/Desktop/codes/leetcode/152-MaximumProductSubarray/Solution.cc
 * Project: /home/jx/Desktop/codes/leetcode
 * Created Date: Saturday, September 23rd 2017, 5:59:47 pm
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
    int maxProduct(vector<int>& nums) {
        int minP = nums[0];
        int maxP = nums[0];

        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int tmin = minP*nums[i];
            int tmax = maxP*nums[i];
            
            maxP = max(max(tmin, tmax), nums[i]);
            minP = min(min(tmin, tmax), nums[i]);
            ans = max(maxP, ans);
        }
        return ans;
    }
};