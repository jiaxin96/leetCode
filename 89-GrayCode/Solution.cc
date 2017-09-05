/**
 * File: e:\code\leetCode\89-GrayCode\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Tuesday, September 5th 2017, 7:01:26 pm
 * Author: JX
 * -----
 * Last Modified: Tue Sep 05 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

 class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ans;
		int c = (int)pow(2, n);
		for (int i = 0; i < c; ++i) {
			ans.push_back(nextGrayCode(i));
		}
		return ans;
	}
	int nextGrayCode(int num) {
		if (num == 0) return 0;
		int c = 0;
		int ans = 0;
		while (num != 0) {
			int pos = num & 1;
			int pre = (num & 2) >> 1;

			int t = (pos^pre) << c;
			ans |= t;
			c++;
			num >>= 1;

		}
		return ans;
	}
};
