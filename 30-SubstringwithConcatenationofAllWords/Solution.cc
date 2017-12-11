#include<map>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> m;
        map<string, int> tm;
        vector<int> ans;
        int sf = words[0].length();
        int count = words.size();

        for(int i = 0; i < words.size(); ++i) {
            m[words[i]]+= 1;
            tm[words[i]]+= 1;
        }
        string temp = "";
        for (int i = 0; i < s.length();i++) {
            count = words.size();
            temp = s.substr(i,sf);
            if (m.find(temp) != m.end()) {
                count--;
                m[temp]--;
                for (int j = i+sf; j < s.length();j+=sf) {
                    if (count == 0) break;
                    temp = s.substr(j,sf);
                    if (m.find(temp) != m.end() && m[temp] > 0) {
                        count--;
                        m[temp]--;
                    } else {
                        break;
                    }
                }
                if (count == 0) {
                    ans.push_back(i);
                }
                m = tm;
            }
        }
        return ans;
    }
};
