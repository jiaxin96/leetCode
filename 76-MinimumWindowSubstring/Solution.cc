#include<vector>
#include<iostream>
#include<string>
#include<limits.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0) return "";
        vector<int> remaining(128, 0);
        // 还有多少个没有匹配
        int required = t.size();
        for (int i = 0; i < required; i++) remaining[t[i]]++;
        // left is the start index of the min-length substring ever found
        int min = INT_MAX, start = 0, left = 0, i = 0;
        // i 为 s.size()的时候如果required为0说明最后一个s的字符在t中有出现,需要更新
        while(i <= s.size() && start < s.size()) {
            if(required) {
                if (i == s.size()) break;
                // 无论如何先减去,只在S的字符会小于0
                // 在T中的会大于等于0
                remaining[s[i]]--;
                // s[i]是在t中的
                if (remaining[s[i]] >= 0) required--;
                i++;
            } else {
                // 已经全部找到 更新最小窗口和起始位置
                if (i - start < min) {
                    min = i -start;
                    left = start;
                }
                remaining[s[start]]++;
                // 如果是t的字符那么就会满足remaining[s[start]] > 0
                // required++ 的原因是下一次的起点要向前移动一次,那么本次匹配的起点如果是一个t的字符
                // 就要补上去继续去找这个字符,形象的表示就是
                // 假设本次找到了 S的[ start......j ] 这之间的字符包涵T的所有字符
                // 那么如果start是T的一个字符
                // 下一次只用在区间 [ j... ] 即j之后在找一个字符就可以了
                // 如果不是或者是重复的值(例如S= aaaaaaab, T=ab, a会重复多次)那么就可以把起点不断的向前移动.
                if (remaining[s[start]] > 0) required++;
                start++;
            }
        }
        return min == INT_MAX? "" : s.substr(left, min);
    }
};

int main() {
    Solution s;
    cout << s.minWindow("ab", "b");
}