# Leetcode 152-MaximumProductSubarray 解题报告

---

**题目**
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

---

**分析**

这道题和53题找到数组中连续和最大的序列类似,需要维护全局最大和局部最大.
不同的是连续和有可能是一个小的片段而且只可能是不断的从局部和最大的里面挑,
但是乘积的最大有可能是由乘积最小的那个数字乘上一个负数然后变成最大.所以我们要维护2个局部数组,局部最大和局部最小,后续思路和<a href='http://blog.csdn.net/rjx_1996/article/details/78075019'>53题(具体题目思路点链接)</a>基本一致,
分别计算当前值乘最小值,当前值乘最大值,和当前值3者之间的最大和最小值,
全局最大是3者之间的最大值

---

**AC代码**

```c
 class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minP = nums[0];
        int maxP = nums[0];

        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int tmin = minP*nums[i];
            int tmax = maxP*nums[i];
            
            maxP = max(max(tmin, tmax), nums[i]);
            minP = min(min(tmin, tmax), nums[i]);
            ans = max(maxP, ans);
        }
        return ans;
    }
};
```