/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public List<Integer> largestValues(TreeNode root) {
        LinkedList<Integer> ans = new LinkedList<>();

        LinkedList<TreeNode> que = new LinkedList<>();

        int maxnum = 0, curmax = 0;

        TreeNode cur = root, last = root, nlast = root;

        if (root != null) {
        	// ans.add(root.val);
        	que.add(root);
        	maxnum = root.val;
        	curmax = root.val;
        }

        int leval = 1;



        while (que.size() != 0) {

        	maxnum = maxnum > que.peek().val ? maxnum : que.peek().val;

        	cur = que.poll();

        	

        	if (cur.left != null) {
        		que.add(cur.left);
        		nlast = cur.left;
        		
        	}

        	if (cur.right != null) {
        		que.add(cur.right);
        		nlast = cur.right;
        		
        	}

        	if (cur == last) {
        		last = nlast;
        		ans.add(maxnum);
        		if (que.size() > 0) {
        			maxnum = que.peek().val;
        		}
        	}

        }

        return (List)ans;

    }
}