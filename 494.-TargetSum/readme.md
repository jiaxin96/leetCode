# leetcode 494.-TargetSum 解题报告
---

**题目**
>> You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.

```
Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
```

>>There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.

----
**分析**
>> 题目要求对一个数组的所有值进行加或者减得到目标值一共有多少种计算方法.显然直观的方法是DFS,定义函数helper(i,cur,tar count)
i表示正在计算数组第几个数字, tar表示目标, cur表示当前的加减和
count表示目前的方法数.但是这种方法使用2叉树,高度为数组长度,
复杂度为O(2^(len))比较高.我们使用数学转化可以得到问题的线性解.
假设这些正数中我们取加号的数字组成子集P, 整个数组为总集U
则有Sum(P)-Sum(U-P)=target -->  Sum(P)-(Sum(U)-Sum(P))=target --> 2*Sum(P)-Sum(U)=target
最终得到Sum(P) = (target+Sum(U))/2.
于是这个问题就变成从一个数组中能找到多少子集使得子集的和为(target+Sum(U))/2.
这是经典的01背包问题,可用动态规划解决,设二维数组dp[i][j], 表示数组前i个数能达到和为j的子集的数量,那么有状态转移方程,
dp[i][j] = dp[i-1][j] + dp[i-1[j-nums[i]],这个式子的含义是
当判断到数字第i个数字的时候可以选也可以不选,那么就有2中可能,
于是数组前i个数能达到和为j的子集的数量等于不选第i个的数字累加和为j的子集数量
加上选了第i个累加和为j-nums[i]的子集的数量.
基于上面的状态转移方程可以写出如下的循环
```c
for (int i = 0; i < nums.size(); ++i) {
    for (int j = nums[i]; j <= sum; ++j) {
        dp[i][j] = dp[i-1][j]+dp[i-1][j-nums[i]];
    }
}

```

>>这里使用了2维数组,但是01背包可以通过滚动数组来降低为1维,
何为滚动数组,就是数组的下一行值依赖与上一行值,这就可以通过一维数组来做到.
于是状态方程写为
dp[j] = dp[j] + dp[j-num[i]]
但是由于每一行都依赖上面的一行,怎么做到不重复计算,方法就是逆序,
内层循环使用**逆序**就可以做到
于是可以写出如下循环
```c
for (int i = 0; i < nums.size(); ++i) {
    for (int j = sum; j >=nums[i] ; --j) {
        dp[j] = dp[j]+[j-nums[i]];
    }
}
```

实解决这个问题的时候需要注意无解的情况
1.目标比所有的值加起来还大.
2.Sum(U)+target是奇数.

---

**AC代码**

```C
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int target = 0;
        for (int i = 0; i < nums.size(); ++i) {
            target += nums[i];
        }
        if(S > target || (S+target)%2 != 0) return 0;
        target = (target+S)/2;


        vector<int> dp(target+1, 0);
        dp[0] = 1;
        // 这里是01背包问题的一维数组解法.
        for (int i : nums) {
            for (int j = target; j >= i; --j) {
                dp[j] += dp[j-i];
            }
        }
        return dp[target];
    }
};
```