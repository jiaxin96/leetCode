#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
using namespace std;
class Solution {
public:
string simplifyPath(string path) {
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);
    while(getline(ss,tmp,'/')) {
        if (tmp == "" or tmp == ".") continue;
        if (tmp == ".." and !stk.empty()) stk.pop_back();
        else if (tmp != "..") stk.push_back(tmp);
    }
    for(auto str : stk) res += "/"+str;
    return res.empty() ? "/" : res;
}
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout <<  s.simplifyPath("/a/./b/../../c/");
	return 0;
}