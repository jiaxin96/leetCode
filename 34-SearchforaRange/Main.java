import java.util.LinkedList;

/**
 * File: /home/jx/Desktop/codes/leetcode/34-SearchforaRange/Main.java
 * Project: /home/jx/Desktop/codes/leetcode
 * Created Date: Friday, July 28th 2017, 8:38:09 pm
 * Author: JX
 * -----
 * Last Modified: Fri Jul 28 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * All shall be well and all shall be well and all manner of things shall be well.
 * We're doomed!
 */

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        for (int i : s.searchRange(new int[]{1,2,3}, 2))
            System.out.println(i);
    }
}
class Solution {

    public int[] searchRange(int[] nums, int target) {
        int pos = biSearch(nums, target, 0, nums.length-1);
        
        if (pos == -1) {
            System.out.println("#####");
            return new int[] {-1,-1};
        }
        // front
        int [] ans = new int[2];
        int i = pos;
        for (i = pos; i >= 0; i--) {
            if (nums[i] == target) ans[0] = i;
        }
        ans[1]  = pos;
        for (i = pos + 1; i < nums.length; ++i) {
            if (nums[i] == target) ans[1] = i;
        }
        return ans;
    }

    public int biSearch(int [] nums, int target, int b, int e) {
        if (b>e) {
            return -1;
        } 
        int m = (b+e)/2;
        if (nums[m] > target) {
            return biSearch(nums, target, b, m-1);
        } else if (nums[m] < target) {
            return biSearch(nums, target, m+1, e);
        } else {
            return m;
        }
    }
}

