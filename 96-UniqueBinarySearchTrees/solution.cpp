#include <vector>
class Solution {
public:
	int numTrees(int n) {
		std::vector<int> v;
		v.push_back(2);
		v.push_back(1);
		if (n == 1) return 1;
		for (int i = 2; i <= n; ++i)
		{
			int cur = 0;
			for (int j = i - 1; j >= 1; --j)
			{
				cur += v[j]*v[i-1-j];
			}
			v.push_back(cur);
		}

		return v[n];
	}
};