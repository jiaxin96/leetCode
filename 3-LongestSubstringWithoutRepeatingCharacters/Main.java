import java.util.*;

class Solution {

	private int indexOfChar;

	public int lengthOfLongestSubstring(String s) {
		String pre, pos;
		int ans = 0;
		String maxStr = "";

		char[] ts = s.toCharArray();

		for (int i = 0; i < ts.length; ++i) {
			if (hasChar(maxStr, ts[i])) {

				ans = ans > maxStr.length() ? ans : maxStr.length();

				if (indexOfChar == maxStr.length() - 1) {
					maxStr = "";
				} else {
					maxStr = maxStr.substring(indexOfChar + 1);
				}

			}

			maxStr = maxStr + ts[i];
			
		}


		ans = ans > maxStr.length() ? ans : maxStr.length();

		return ans;

	}


	private boolean hasChar(String s, char c) {
		char[] ts = s.toCharArray();
		for (int i = 0; i < ts.length; ++i) {
			if (c == ts[i]) {
				indexOfChar = i;
				return true;
			}
		}

		return false;
	}
}




public class Main {
	public static void main(String[] args) {
		Solution ss = new Solution();
	}
}
