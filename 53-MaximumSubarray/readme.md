# Leetcode 53-Maximum Subarray 解题报告

---

**题目**

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

---

**分析**

题目要找到数组的一段最大的序列和.一次遍历的方法不太好想.我们考虑使用动态规划的方法,划分子问题.
curSum[i]表示遍历到nums数组的i位时数组某个位置到i的连续和的最大值,这个和大于等于nums[i]
这里需要使用的思路是局部最大和全局最大,构造一个curSum记录直到当前遍历的数字值为止的连续序列和来表示局部最大.
同时构造一个maxSum表示全局最大.
当前的和的前一个局部和只要大于0那么就对局部和有正作用,否则我们就设置当前和从当前的点重新开始,

>数学表示就是:
>if curSum[i-1] <= 0 then curSum[i] = nums[i] 
>else if curSum[i-1] > 0 then curSum[i] =  curSum[i-1]+nums[i]

同时每次变更局部和的时候和全局和比较并记录最大的哪一个.
如果考虑记录下这个序列的起止下表,需要维护3个变量,pos表示局部和的起点,left表示全局和的起点,right表示全局和的终点.

---

**AC代码**

```c
 class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curSum = nums[0];
        int curBegin = 0, leftIndex = 0, rightIndex = 0;
        for (int i = 1; i < nums.size(); ++i) {
            curSum += nums[i];
            if (curSum < nums[i]) {
                curSum = nums[i];
                curBegin = i;
            }
            if (curSum > maxSum) {
                maxSum = curSum;
                leftIndex = curBegin;
                rightIndex = i;
            }
        }
        return maxSum;
    }
};
```