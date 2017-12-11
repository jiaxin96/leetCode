#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s == "" && p == "") return true;
        if (s == "" || p == "") return false;
        int l = p.length();
        int sf = 0;
        for (int i  = 0; i < l; ++i) {
            if (sf == s.length()) return true;
            if (p[i] == '*') {
                bool tt = false;
                for (int j = 0; j < s.length()-sf; ++j) {
                    tt |= isMatch(s.substr(sf+j), p.substr(i+1));
                }
                return tt;
            } else if (p[i] == '?') {
                sf++;
            } else if (p[i] != s[sf]) {
                return false;
            } else {
                sf++;
            }
        }
        if (sf == s.length())
            return true;
        else
            return false;
    }
};