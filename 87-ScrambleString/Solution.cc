#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        vector<vector<vector<int>>> dp(s1.length(), vector<vector<int>>(s2.length(),vector<int>(s1.length()+1, 0)));
        for (int i = s1.length()-1; i >= 0; i--) {
            for (int j = s2.length()-1; j >= 0; j--) {
                for (int k = 1; k <= s2.length()-max(i,j); k++) {
                    if (s1.substr(i,k)==s2.substr(j,k)) {
                        dp[i][j][k] = true;
                   } else {
                       for (int l=1; l<k; l++)
                        {
                            if(dp[i][j][l] && dp[i+l][j+l][k-l] || dp[i][j+k-l][l] && dp[i+l][j][k-l])
                            {
                                dp[i][j][k]=true;
                                break;
                            }
                        }
                   }
                }
            }
        }
        return dp[0][0][s1.length()];

    }
};
