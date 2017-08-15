/**
 * File: e:\code\leetCode\57-InsertInterval\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Tuesday, August 15th 2017, 8:51:47 am
 * Author: JX
 * -----
 * Last Modified: Tue Aug 15 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        intervals.push_back(newInterval);
        if (intervals.size() <= 0) {
            return ans;
        }
        sort(intervals.begin(), intervals.end(), [=](Interval a, Interval b)->int{if (a.start == b.start) return a.end < b.end; else return a.start < b.start;});

        int s = intervals[0].start, b = intervals[0].end;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= b) {
                b = max(intervals[i].end, b);
            } else {
                ans.push_back(Interval(s,b));
                s = intervals[i].start;
                b = intervals[i].end;
            }
        }
        ans.push_back(Interval(s,b));
        return ans;
    }
};