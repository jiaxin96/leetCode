class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        helper(ans, tmp, s);
        return ans;
    }
    void helper(vector<vector<string>>& ans, vector<string> & tmp, string s) {
        if (s == "") {
            ans.push_back(tmp);
            return;
        }
        int l = s.length();
        for (int i = 0; i < l; ++i){
            if (isPalind(s.substr(0, i+1))) {
                tmp.push_back(s.substr((0, i+1);
                helper(ans, tmp, s.substr(i+1));
                tmp.pop_back();
            }
        }
    }
    bool isPalind(string s) {
        int l = s.length();
        for (int i = 0; i < l/2; ++i) {
            if (s[i] != s[l-1-i]) {
                return false;
            }
        }
        return true;
    }
};
