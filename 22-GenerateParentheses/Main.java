public class Main {
	public static void main(String[] args) {
		
	}
}
class Solution {
    public List<String> generateParenthesis(int n) {
    	int left = n, right = 0;

    	List<String> ans = new LinkedList<>();
    	
    	getAns(0, 0, "", ans, n);
    	
    	return ans;
    }


    void getAns(int right, int left, String s, List<String> ans, int n) {
    	if (right == n && left == n) {
    		ans.add(s);
    		return;
    	}
    	if (right < n) {
    		getAns(right+1, left, s+"(", ans, n);
    	}
    	if (left < right && left < n) {
    		getAns(right, left+1, s+")", ans, n);
    	}
    }

}