# Leetcode 

**题目**

>> Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.

---


**分析**


>> 题目要求找到需要添加到数组使得数组中的数字的和可以组合出[1,n]的任意数字的最小个数。
比较简单的贪心算法，使用一个up记录当前集合已经完成[0, up)所有组合。
当前值nums[i]小于等于up时，表示在集合中增加nums[i]可以使组合范围增大到[0, up+nums[i])。
当前值nums[i]大于up时，增加nums[i]并不能让集合覆盖[0, up+nums[i])而是[0,up)并[nums[i], nums[i]+up)，此时最好的方法是加一个up，使得范围增大到[0, 2 * up)。

---


**AC代码**


```c
class Solution
{
  public:
    int minPatches(vector<int> &nums, int n)
    {
        long up = 1;
        int ret = 0, i = 0;
        while (up <= n)
        {
            if (i < nums.size() && nums[i] <= up)
            {
                up += nums[i++];
            }
            else
            {
                up <<= 1;
                ++ret;
            }
        }
        return ret;
    }
};
```