public class Main {
	public static void main(String[] args) {
		
	}
}

class Solution {
    public int numDecodings(String s) {
        if (s.length() == 0) return 0;
        int [] dp = new int[s.length()+1];
        dp[0] = 1;
        dp[1] = (s.charAt(0) == '0') ? 0 : 1;



        for (int i = 2; i <= s.length(); ++i) {
        	int t = 0;
        	t = 10*(s.charAt(i-2)-'0')+s.charAt(i-1)-'0';
        	if (t>=10 && t<=26) dp[i] += dp[i-2];
        	if (s.charAt(i-1)>='1' && s.charAt(i-1)<='9') dp[i] += dp[i-1];
        }
        return dp[s.length()];
    }
}