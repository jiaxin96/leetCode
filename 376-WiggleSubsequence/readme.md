# Leetcode 376. Wiggle Subsequence 解题报告

**题目**
>> A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.
For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.
Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

**例子**
>> Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2

---

**分析**
>> 乍一看这是一个典型的动态规划问题，都是最...子序列和最...子串问题。这些问题有通用的解法，对于子序列问题可以令数组dp[i]表示以第i个数字结尾的自序列的最长（小）长度，那么有dp[i] = dp[k]+1, k=0,1,2...,i-1, 只要数组第k个数字满足条件。最后的答案取dp中的最大（小）值。

>> 对于这一道题目，我们引入另一个记录符号的数组signs，signs[i]表示第i个数字最为序列最后一个的时候和倒数第二个的差的符号，那么有对应的状态转移方程dp[i] = max(dp[i], dp[k]+i), 其中k满足signs[k] * (nums[i] - nums[k]) < 0 ， 表示第当前第i个数字和第k个数字的差的符号同第k个数字和它前一个的数字差符号相反，需要注意一下特殊情况就是所有的数字都相同的时候的情况，于是可以得出动态规划的算法，代码在下方。
---

**AC代码**

```c
class Solution
{
  public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        if (nums.size() == 2)
        {
            return (nums[0] == nums[1]) ? 1 : 2;
        }
        vector<int> dp(nums.size(), 0);
        vector<int> signs(nums.size(), 0);
        dp[0] = 1;
        int maxl = 1;
        signs[1] = (nums[1] - nums[0] > 0) ? 1 : -1;
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (signs[j] == 0 || signs[j] * (nums[i] - nums[j]) < 0)
                {
                    if (dp[j] + 1 >= dp[i] && nums[i] != nums[j])
                    {
                        dp[i] = max(dp[i], dp[j] + 1);
                        signs[i] = (nums[j] - nums[i] > 0) ? -1 : 1;
                    }
                }
            }
            maxl = max(maxl, dp[i]);
        }
        return maxl;
    }
};
```