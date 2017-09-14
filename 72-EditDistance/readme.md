# leetcode 72. Edit Distance 解题报告
---
**描述**
>Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character

c) Replace a character
---

**分析**
题目要求找到2个字符串之间的最小距离
定义执行特定变换可以转换为另一个字串的次数:
操作有
1.插入
2.删除
3.替换
最简单的思路就是先比较长度,计算出需要插入的次数或者删除的次数,
然后按照目标串的字符排列字符排列遍历得到需要替换的次数这个操作要每次都遍历一次目标串,复杂度为O(n^2)

现在使用动态规划的思想考虑
使用矩阵dp[i][j]来表示str1的前i项变换到str2的前j项需要的最小操作次数.
可以得到下面的递推公式:
<font color="red">
<pre>
if (str1[i] == str2[j]) // 当最后一个字符相同的时候
    // 那么变换的最小值就是两个字符都去掉最后一个的情况
    <strong>dp[i][j] = dp[i-1][j-1];</strong>
else // 如果最后一个字符不相同
    // 那么变换的最小值就是str1去掉最后一个字符在加一次删除操作
    /* 
    例如
    str1     str2    需要操作的次数
    123 ---> 2345  =   dp[i][j]
    12 ----> 2345  =   dp[i-1][j]
    由于3!=5 那么可以知道 123-->12需要一次删除操作,
    那么dp[i][j]通过123变为2345就要
    先从123-->12在12---->2345,
    总共需要dp[i-1][j]+1次操作
    */
    // 或者str2去掉一个字符再加一次插入操作
    // 或者str1和str2都去掉最后一个字符外加一次替换操作
    // 最终答案为3者的最小值
    <strong>dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;</strong>
</pre>
</font>

---

**AC代码**
```c
class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.length()+1][word2.length()+1] = {{0}};
        for (int i = 0; i <= word1.length(); ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= word2.length(); ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= word1.length(); ++i) {
            for (int j = 1; j <= word2.length(); ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
};
```
