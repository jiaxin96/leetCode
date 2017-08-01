#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	
	return 0;
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<int> path;
            vector<vector<int>> result;
            result.push_back(path);
            sort(nums.begin(),nums.end());
            helper(nums,0,path,result);
            return result;
    }

    void helper(vector<int> &nums,int pos,vector<int>& path,vector<vector<int>> &result)
    {
        if(pos==nums.size())
            return ;

        for(int i=pos;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            result.push_back(path);
            helper(nums,i+1,path,result);
            path.pop_back();
            while(nums[i]==nums[i+1]) i++;
        }
    }
};