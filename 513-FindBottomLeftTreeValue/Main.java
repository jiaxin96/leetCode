/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int findBottomLeftValue(TreeNode root) {
        int h = getH(root);
        return ans(root, h, 0);
    }

    int getH(TreeNode root) {
    	if (root == null) return 0;

    	int l = 0, r = 0;

    	if (root.left != null) {
    		l = getH(root.left);
    	}

    	if (root.right != null) {
    		r = getH(root.right);
    	}

    	return r > l : r + 1 : l + 1;

    }


}
public class Main {
	public static void main(String[] args) {
		
	}
}

