class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        int ans = 0;
        s = ')'+s;
        vector<int> dp(s.length(), 0);
        for (int i = 2; i < s.length(); ++i) {
            if (s[i] == ')') {
                if (s[i-1] == '(') dp[i] = dp[i-2]+2;
                else if (dp[i-dp[i-1]-1] == '(') dp[i] = dp[i-1]+dp[i-dp[i-1]-2]+2;
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
