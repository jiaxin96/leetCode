/**
 * File: e:\code\leetCode\45-JumpGameII\Solution.java
 * Project: e:\code\leetCode
 * Created Date: Monday, August 7th 2017, 11:50:42 pm
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

public class Solution {
    public int jump(int[] A) {
        int n = A.length;
        int range = 1; // 第1跳能及的最远范围
        int next = 0; // 第2跳能及的最远范围
        int i = 1;
        int count = 0;

        while (range < n) {
            if (i <= range) {
                next = next > i + A[i - 1] ? next : i + A[i - 1];
                i++;
            }
            else {
                count++;
                range = next;
            }
        }

        return count;
    }
}