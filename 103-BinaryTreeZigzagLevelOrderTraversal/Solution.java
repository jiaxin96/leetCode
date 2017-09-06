/**
 * File: e:\code\leetCode\103-BinaryTreeZigzagLevelOrderTraversal\Solution.java
 * Project: e:\code\leetCode
 * Created Date: Wednesday, September 6th 2017, 1:55:35 pm
 * Author: JX
 * -----
 * Last Modified: Wed Sep 06 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.util.concurrent.LinkedBlockingDeque;
public class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
         Queue<TreeNode> q = new LinkedList<>();
        List<List<Integer>> l = new LinkedList<>();
        
        if (root == null) {
            return l;
        }
        boolean isOdd = false;
        try {
            
        q.add(root);
        
    
        int s = q.size();
        while (q.size() != 0) {
            List<Integer> tmp = new LinkedList<>();
            s = q.size();
            for (int i = 0; i < s; ++i) {
                TreeNode f = q.poll();
                if (isOdd) {
                    tmp.add(0,f.val);
                } else {
                    tmp.add(f.val);
                }
                if (f.left != null) q.add(f.left);
                if (f.right != null) q.add(f.right);

            }
            isOdd = !isOdd;
            l.add(tmp);
            
        }
            }
    catch(Exception e) {
            
        }
        return l;
    }
}