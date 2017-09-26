/**
 * File: e:\code\leetCode\207-CourseSchedule\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Wednesday, September 27th 2017, 12:20:54 am
 * Author: JX
 * -----
 * Last Modified: Wed Sep 27 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<vector<int>> cmap;
        cmap.resize(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            cmap[i].resize(numCourses);
        }
        for (auto it : prerequisites) {
            cmap[it.second][it.first] = 1;
        }

        bool ans = true;
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) {
                ans &= dfs(visited, cmap, i,numCourses);
            }
        }
        return ans;
    }

    bool dfs(vector<int>& visited, vector<vector<int>>& cmap, int cp, int numCourses) {
        visited[cp] = 1;
        bool ans = true;
        for (int i = 0; i <numCourses; ++i) {
            if (cmap[cp][i] ==1 && visited[i] == 0) {
                ans &= dfs(visited, cmap, i, numCourses);
            } else if (cmap[cp][i]==1 && visited[i] == 1) {
                return false;
            }
        }
        visited[cp] = 2;
        return ans;
    }
};