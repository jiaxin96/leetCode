/**
 * File: /home/jx/Desktop/codes/leetcode/31-NextPermutation/Main.java
 * Project: /home/jx/Desktop/codes/leetcode
 * Created Date: Tuesday, July 4th 2017, 2:39:14 pm
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
		
	}
}

//  1 2 5 (6) 8 (7) 4 3 1
//  1 2 5 (7) 8 (6) 4 3 1

class Solution {
    public void nextPermutation(int[] nums) {
        if (nums.length <= 1) return;
        int pos = nums.length-1;
        for (; pos > 0; pos--) {
            if (nums[pos-1] < nums[pos]) break;
        }
        if (pos == 0) {
            reverse(nums, 0, nums.length-1);
            return;
        }
        int i = nums.length-1, k = nums[pos-1];
        for(; i > pos-1; i--) {
            if (nums[i] > k) {
                break;
            }
        }
        int t = nums[i];
        nums[i] = nums[pos-1];
        nums[pos-1]  = t;
        reverse(nums, pos, nums.length-1);
        
    }
    public void reverse(int[] nums, int b, int e) {
        int t = 0;
        for (int i = b; i <= (b+e)/2; ++i) {
            t  = nums[i];
            nums[i] = nums[e+b-i];
            nums[b+e-i] = t;
        }
    }
}