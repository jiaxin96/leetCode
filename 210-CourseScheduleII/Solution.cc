/**
 * File: e:\code\leetCode\210-CourseScheduleII\Solution.cc
 * Project: e:
 * Created Date: Monday, October 16th 2017, 2:19:46 pm
 * Author: JX
 * -----
 * Last Modified: Mon Oct 16 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

 class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> cmap(numCourses, vector<int>(numCourses, 0));
        for (pair<int , int> pp : prerequisites) {
            cmap[pp.second][pp.first] = 1;
        }
        bool hasR = false;
        vector<int> visited(numCourses, 0);
        vector<int> ans;
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) {
                visited[i] = 1;
                dfs(visited, ans, cmap, i,numCourses, hasR);
            }
        }
        for (int i = 0; i < ans.size()/2; ++i) {
            int t = ans[i];
            ans[i] = ans[ans.size()-1-i];
            ans[ans.size()-1-i] = t;
        }
        return hasR == true ? vector<int>() :  ans;
    }
    void dfs(vector<int>& visited, vector<int>& ans, vector<vector<int>>& cmap, int s,int n, bool & hasR) {
        
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0 && cmap[s][i]) {
                visited[i] = 1;
                dfs(visited, ans, cmap, i, n, hasR);
            }
            if (visited[i] == 1 && cmap[s][i]) {
                hasR = true;
            }
        }
        visited[s] = 2;
        ans.push_back(s);
    }
};