/**
 * File: /home/jx/Desktop/codes/leetcode/137-SingleNumberII/Solution.cc
 * Project: /home/jx/Desktop/codes/leetcode
 * Created Date: Saturday, September 23rd 2017, 11:07:37 am
 * Author: JX
 * -----
 * Last Modified: Sat Sep 23 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * All shall be well and all shall be well and all manner of things shall be well.
 * We're doomed!
 */



 class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < 32; ++j) {
                int t = (1)&(nums[i]>>j);
                if ( t== 1) count[j]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            count[i] %= 3;
            ans <<= 1;
            ans |= count[i];
        }
        return ans;

    }
};
