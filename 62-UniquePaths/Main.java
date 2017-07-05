public class Solution {
    public int uniquePaths(int m, int n) {
        int p = 1;

        for (int i = 2; i <= n; ++i) {
        	p =  (int)Math.round(p *  ( (double)(i+m-2) / (double)(i-1) ) );
        }
        return p;
    }
}