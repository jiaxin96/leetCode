import java.util.*;
public class Main {


	public static void main(String[] args) {
		
	}
}


class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);

        int count = 0;

        for (int i = 0; i < g.length && count <= s.length; ++i) {
        	for (int j = 0; j < s.length; ++j) {
        		if (g[i] <= s[j]) {
        			count++;
        			s[j] = -1;
        			break;
        		}
        	}
        }

        return count;
    }
}