# Leetcode 32 Longest Valid Parentheses 解题报告。
---
**题意**
>> Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring. 
For "(()", the longest valid parentheses substring is "()", which has length = 2. 
Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
---
**分析**
要求是求出给定的括号字符串中最长的合法子序列。
首先我们判断一个括号序列是否合法的方法是使用栈的方法。
于是显然的可以将每个位置的字符作为起始符号，分多次运行这个判断是否合法的子程序，这样计算的时间复杂度为O(N^2)
对于字符串类型的问题可以尝试使用动态规划的方法，先尝试使用一维的动态规划
设字符串为S
取dp[i]表示从0到第i个位置得到的最长合法串，则dp[i+1]难以计算，由于只能利用前一个的信息，即S[i]和dp[i]
所以难以找到dp[i+1]的迭代计算方式。
> 考虑使用二维的动态规划，
dp[i, j]，表示从字符串的第i个到第j个字符之间合法的字符串的最大长度。
可以得到 dp[i+1, j+1]的计算方式如下
               |dp[i,j]+2, if S[i+1]=='(' and S[j+1] == ')'
dp[i+1, j+1] = |
               |dp[i,j], if S[i+1]=='(' and S[j+1] != ')' or S[i+1] == '('
初始化d[0][0] = 1
答案为dp[0][n]
编码如下：
但是这样看似很好但是却无法实现，由于计算得到dp[i,j] 需要dp[i,j-1] dp[i+1,j], dp[i+1, j-1], 但是j>=i,
所以需要使用一个数字的斜上方和正上方和左边的值来得到一个值，这样的方式需要dp矩阵首先计算出第一行，这显然不行，所以变换思路

依然考虑使用一维dp的方法，但是需要改变dp数组的意义，令dp[i]表示以第i个符号作为结尾的一个合法字符串的最大长度（显然只有‘）’才能作为最后一个符号），只是这里需要每次记录一下dp的值取其中的最大值，本身dp[n]不代表答案。
于是有
ans = 0
>> if (s[i] == ')') {
    // 表示可以将上一个匹配的符号串包起来
    // eg: 
    //               dp[i-dp[i-1]-2]         k    k+1              k+dp[i-1]    i
    // )) (()) ())     )                     (    (   ) ()()()()(    )          )
    // 可得dp[i] =   dp[i - dp[i-1] - 1]+dp[i-dp[i-1]-2] + 2;
    //
    if (s[i-dp[i-1] -1] =='(') {
        dp[i] = dp[i - dp[i-1] - 1]+dp[i-dp[i-1]-2] + 2;
    }
    ans = max(ans, dp[i]);
}
最终答案为ans.

---

题目的思考：
本题开始就考虑直接用dp数组作为最终的子问题答案所以导致无法继续分析，然后开始考虑二维的dp但是遇到了不可求的情况，
这表明在同一个数组上进行二维的dp一般是不可行的这就需要变换思路，不要直接用dp作为答案，考虑每次更新答案，从子问题中挑选最优的一个作为答案，这样有可能在更低的维度解决问题。

---
**AC代码**
```c
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
```
