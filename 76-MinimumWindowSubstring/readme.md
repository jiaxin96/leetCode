# Leetcode 76-MinimumWindowSubstring 解题报告

**题目**
>> Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
Note:
If there is no such window in S that covers all characters in T, return the empty string "".
If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

---

**解析**
>> 乍一看这个题目我先想到的是动态规划,但是考虑使用一个二维的dp暂且不管复杂度为n^2,由于S串的一个子串包涵T串的字母即可,不要求有顺序,
要使用dp的话其实隐含必须要有顺序,因为找的是dp[i][j] 和 dp[n][m]的关系,其中满足i<=n, j<=m, 且不同时等与,这样的话,就要求了j和m或者i和n在串中的相对位置,所以暂时没有想到正确的dp思路.

>> 换一个思路使用类似bitset的方法使用一个一维数组来计数ascii的128位2字符,先统计t的字符,然后遍历s串,记录匹配到的数量,每次完全找到所有的t的字符后
就更新一次最小值和起始点,需要注意的是当最后一个S的字符是一个T的字符并且使用到了这个字符来匹配也要记录一下.
具体代码如下,细节参见注释.
---

```c
#include<vector>
#include<iostream>
#include<string>
#include<limits.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0) return "";
        vector<int> remaining(128, 0);
        // 还有多少个没有匹配
        int required = t.size();
        for (int i = 0; i < required; i++) remaining[t[i]]++;
        // left is the start index of the min-length substring ever found
        int min = INT_MAX, start = 0, left = 0, i = 0;
        // i 为 s.size()的时候如果required为0说明最后一个s的字符在t中有出现,需要更新
        while(i <= s.size() && start < s.size()) {
            if(required) {
                if (i == s.size()) break;
                // 无论如何先减去,只在S的字符会小于0
                // 在T中的会大于等于0
                remaining[s[i]]--;
                // s[i]是在t中的
                if (remaining[s[i]] >= 0) required--;
                i++;
            } else {
                // 已经全部找到 更新最小窗口和起始位置
                if (i - start < min) {
                    min = i -start;
                    left = start;
                }
                remaining[s[start]]++;
                // 如果是t的字符那么就会满足remaining[s[start]] > 0
                // required++ 的原因是下一次的起点要向前移动一次,那么本次匹配的起点如果是一个t的字符
                // 就要补上去继续去找这个字符,形象的表示就是
                // 假设本次找到了 S的[ start......j ] 这之间的字符包涵T的所有字符
                // 那么如果start是T的一个字符
                // 下一次只用在区间 [ j... ] 即j之后在找一个字符就可以了
                // 如果不是或者是重复的值(例如S= aaaaaaab, T=ab, a会重复多次)那么就可以把起点不断的向前移动.
                if (remaining[s[start]] > 0) required++;
                start++;
            }
        }
        return min == INT_MAX? "" : s.substr(left, min);
    }
};

int main() {
    Solution s;
    cout << s.minWindow("ab", "b");
}
```