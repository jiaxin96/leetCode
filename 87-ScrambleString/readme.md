# leetcoed 87 Scrcmble String 解题报告
---
**题目**
<div class="question-description">
        <p></p><p>
Given a string <i>s1</i>, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
</p>
<p>
Below is one possible representation of <i>s1</i> = <code>"great"</code>:
</p>
<pre>    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
</pre>
<p>
To scramble the string, we may choose any non-leaf node and swap its two children.
</p>
<p>
For example, if we choose the node <code>"gr"</code> and swap its two children, it produces a scrambled string <code>"rgeat"</code>.
</p>
<pre>    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
</pre>
<p>
We say that <code>"rgeat"</code> is a scrambled string of <code>"great"</code>.
</p>
<p>
Similarly, if we continue to swap the children of nodes <code>"eat"</code> and <code>"at"</code>, it produces a scrambled string <code>"rgtae"</code>.
</p>
<pre>    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
</pre>
<p>
We say that <code>"rgtae"</code> is a scrambled string of <code>"great"</code>.
</p>
<p>
Given two strings <i>s1</i> and <i>s2</i> of the same length, determine if <i>s2</i> is a scrambled string of <i>s1</i>.
</p><p></p>
</div>
---

**解析**
>> 题目的意思非常简单,意思是找到一个字符串的二叉树后选择一个节点或多个将他的子节点的左右顺序交换
   然后重新组合成一个新的字符串,这个新的字符串就是原来字符串的一个Scramble.现在给出两个字符串,
   判断后一个字符串是不是前一个的一个Scramble.

---

**分析**
>> 可以想见，原字符串对应的"Scramble”串s1，定然满足如下规律：
如果将“Scramble”串同样从第i个位置割开，他同样可以形成两个子串，s1.substr(0,i)和s1.substr(i,s1.size()-i)，并且满足：
s1.substr(0,i)是s.substr(0,i)的“Scramble”且s1.substr(i,s1.size()-i)是s.substr(i,s.size()-i)的“Scramble”
或者（因为左右交换的原因）
s1.substr(0,i)是s.substr(s.size()-i)的“Scramble”且s1.substr(i)是s.substr(0,s.size()-i)的“Scramble”
于是可以使用递归调用实现.但是这样实现复杂度高,考虑使用动态规划的方法实现.

>> 由于是2个字符串的比较所以一定使用二维以上的dp数组,取dp[i][j][n]表示字符串s1从i开始和s2从j开始的长度为n的子串的是否为"Scramble"
同上面的分析可以知道
从s1的i开始到i+n,从s2的j开始到j+n,从这之间的某一个点隔开,
存在3种情况使得dp[i][j][n]为真:

1. 如果两个substring相等的话，则为true
对应条件s1.substr(i,n) == s2.substr(j,n)

2. 如果两个substring中间某一个点，左边的(s1)substrings为scramble string，
同时右边的(s2)substrings也为scramble string，则为true
对应条件dp[i][j][k]==true&& dp[i+k][j+k+1][n-k]==true

3. 如果两个substring中间某一个点，s1左边的substring和s2右边的substring为scramble
string, 同时s1右边substring和s2左边的substring也为scramblestring，则为true
对应条件dp[i][j+n-l][k]==true&&dp[i+k][j][n-k]==true

根据上面的状态转移方程可以得到下面的代码,需要注意的是由于dp[i][j]的计算都是通过比i,j大的下标来求解的
所以实际的编码循环的时候要从字符串的后面开始循环.

---

**AC代码**

```c
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
```
