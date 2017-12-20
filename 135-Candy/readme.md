# Leetcode 135 Candy 解题报告

**题目**

>> There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
---

**分析**

>> 题目意思很简单 一列小朋友每人有一个权值，现在发糖权值大的人糖要比两边的人多，每人至少一个，问最少的糖个数。
这个题目我们很自然的想到贪心的思路，每个人给尽量的少那么总和就尽量的少，所以从第一个人开始给1个，以后只要发现比前面的人权值大就多给一颗，这样走到队尾，仔细想一下就可以知道这样其实是满足了每个权值大的人拿到的糖比左边的人大，那么我们倒着来执行一次就可以得到每个权值大的人拿到的糖比右边的大，2者合起来就是答案，需要注意的是这两者之间我们要取较大的值，因为每个值都是比左或者右刚刚大1，所以不能再小。
---

**AC代码**

```c
class Solution
{
public:
  int candy(vector<int> &ratings)
  {
    int ans = 0;
    vector<int> temp(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); ++i)
    {
      if (ratings[i] > ratings[i - 1])
        temp[i] = temp[i - 1] + 1;
    }
    ans += temp[ratings.size() - 1];
    for (int i = ratings.size() - 1; i >= 1; --i)
    {
      if (ratings[i - 1] > ratings[i])
        temp[i - 1] = max(temp[i] + 1, temp[i - 1]);
      ans += temp[i - 1];
    }
    return ans;
  }
};
```