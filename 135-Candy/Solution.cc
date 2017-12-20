/**
 * File: e:\code\leetCode\135-Candy\Solution.cc
 * Project: e:\code\leetCode\135-Candy
 * Created Date: Wednesday, December 20th 2017, 11:19:12 pm
 * Author: JX
 * -----
 * Last Modified: Thu Dec 21 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

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
