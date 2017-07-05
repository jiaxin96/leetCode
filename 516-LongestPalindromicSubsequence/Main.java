public class Main {
	public static void main(String[] args) {
		
	}
}


class Solution {
    public int longestPalindromeSubseq(String s) {
    	int [][] dp = new int[s.length()][s.length()];

    	for (int i = 0; i < s.length(); ++i) {
    		for (int j = 0; j < s.length(); ++j) {
    			dp[i][j] = 0;

    		}
    		dp[i][i] = 1;
    	}

    	for (int i = 1; i < s.length(); ++i) {
    		for (int j = 0; j < s.length() - i; ++j) {
    			int k = j + i;
    			if (s.charAt(k) == s.charAt(j)) {
    				dp[j][k] = dp[j + 1][k - 1] + 2;
    			} else {
    				dp[j][k] = Math.max(dp[j+1][k], dp[j][k-1]);
    			}

    		}
    	}

    	return dp[0][s.length()-1];

    }
}