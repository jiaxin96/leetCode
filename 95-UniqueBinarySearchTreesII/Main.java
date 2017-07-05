import java.util.*;
//   Definition for a binary tree node.
class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
  }
 
class Solution {
    public List<TreeNode> generateTrees(int n) {
    	return getans(1,n);
    }


    List getans(int s, int e) {
    	List<TreeNode> ans = new LinkedList<>();
        if (s>e) {
            ans.add(null);
            return ans;
        }

        if (s==e) {
            ans.add(new TreeNode(s));
            return ans;
        }

        for (int i = s; i <= e; ++i) {
            List<TreeNode> l = getans(s, i-1);
            List<TreeNode> r = getans(i+1, e);
            for (TreeNode lnode : l) {
                for (TreeNode rnode : r) {
                    TreeNode tr = new TreeNode(i);
                    tr.left = lnode;
                    tr.right = rnode;
                    ans.add(tr);
                }
            }
        }
        return ans;

    }


}
public class Main {
	public static void main(String[] args) {
		
	}
}

