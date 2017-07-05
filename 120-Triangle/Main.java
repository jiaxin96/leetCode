public class Main {
	public static void main(String[] args) {
		
	}
}


class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int [][] dp = new int[triangle.size()][];
        for (int i = triangle.size() - 1; i >= 0; --i) {
        	dp[i] = new int[triangle.get(i).size()];
        	for (int j = 0; j < triangle.get(i).size(); ++j) {
        		if (i == triangle.size() - 1) {
        			dp[i][j] = triangle.get(i).get(j);
        		} else {
        			dp[i][j] = Math.min(dp[i+1][j+1], dp[i+1][j]) + triangle.get(i).get(j);
        		}
        	}
        }
        return dp[0][0];
    }
}