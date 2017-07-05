public Main {
	public static void main(String[] args) {
		
	}
}

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean [] dp = new int[s.length()];
        for (int i = 0; i < s.length(); ++i) {
        	dp[i] = false;
        }
      	if (s.length() == 0) return false;
      	if (wordDict.contains(s)) return true;


        dp[0] = wordDict.contains(s.substring(0,1));

        for (int i = 1; i < s.length(); ++i) {

        	dp[i] = wordDict.contains(s.substring(0,i+1));

        	for (int j = i-1; j >= 0; --j) {
        		if (dp[j] && wordDict.contains( s.substring(j+1,i+1) )) {
        			dp[i] = true;
        			break;
        		}
        	}


        }

        return dp[s.length()-1];
    }
}