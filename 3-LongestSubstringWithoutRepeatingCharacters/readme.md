# LeetCode 3. Longest Substring Without Repeating Characters 解题报告

* * *
**题目**
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

* * *
**分析**
>朴素思路每个字符作为开头去遍历，每次需要和前面所有的字符比较复杂度为遍历首字母O(n)*查重O(n^2) = O(n^3)

>O(n)的算法参看别人的代码得到：
由于所有的字符只有256个（扩展的ASICS），所以可以建立一个有256个值的数组dict记录每个值的出现的下标。遍历整个字符串，设立一个起始位置记录量初始化为-1，每当当前字符在数组dict中的值(例如a对应ASICS码97， 则对应dict[97])大于遍历位置的下标时，说明这个字符已经被记录过并且在当前下标有一次出现，这个时候就该刷新答案的长度了，对应的这两个字符之间的长度为**当前下标-dict[当前下标字符] （当前下标字符在c++中可以直接作为整数使用值为本身的ASICS码值）**，然后更新新的起点值，并且刷新最大长度，AC代码如下：

- - -

###### 朴素算法：
```java
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
```
###### O(n)算法
```java
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
```