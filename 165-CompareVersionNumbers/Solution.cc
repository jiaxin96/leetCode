/**
 * File: /home/jx/Desktop/codes/leetcode/165-CompareVersionNumbers/Solution.cc
 * Project: /home/jx/Desktop/codes/leetcode
 * Created Date: Sunday, September 24th 2017, 8:14:38 pm
 * Author: JX
 * -----
 * Last Modified: Sun Sep 24 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * All shall be well and all shall be well and all manner of things shall be well.
 * We're doomed!
 */
 #include <cstring>
 class Solution {
public:
    int compareVersion(string version1, string version2) {
        queue<int> v1;
        queue<int> v2;
        char *p = strtok((char *)version1.c_str(), ".");
        while(p) {
            v1.push(atoi(p));
            p = strtok(NULL, ".");
        }
        p = strtok((char *)version2.c_str(), ".");
        while(p) {
            v2.push(atoi(p));
            p = strtok(NULL, ".");
        }
        
        
        if (v1.size() < v2.size()) {
            while(v1.size()!=v2.size()) v1.push(0);
        
        }
        if (v1.size() > v2.size()) {
            while(v1.size()!=v2.size()) v2.push(0);
        }


        while(!v1.empty() && !v2.empty()) {
            if (v1.front() > v2.front()) return 1;
            if (v1.front() < v2.front()) return -1;
            v1.pop();
            v2.pop();
        }
        if (v1.empty()) {
            if (v2.empty()) {
                return 0;
            } else {
                return -1;
            }
        } else {
            return 1;
        }
    }
};
