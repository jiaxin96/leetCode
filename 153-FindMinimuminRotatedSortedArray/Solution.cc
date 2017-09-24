/**
 * File: /home/jx/Desktop/codes/leetcode/153-FindMinimuminRotatedSortedArray/Solution.cc
 * Project: /home/jx/Desktop/codes/leetcode
 * Created Date: Sunday, September 24th 2017, 7:01:32 pm
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
    int findMin(vector<int>& nums) {
        int b = 0;
        if(nums.size()==1) return nums[0];
        int e = nums.size()-1;
        int mid = (b+e)/2;
        while(b < e) {
            mid = (b+e)/2;
            if (mid == b) {
                return min(nums[e], nums[b]);
            }

            if (nums[mid] > nums[e]) {
                b = mid;
            } else {
                e = mid;
            }
            
            
        }
        return nums[b];
    }
};