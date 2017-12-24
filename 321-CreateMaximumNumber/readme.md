# Leetcode 502 IPO 解题报告

**题目**
>> Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
You are given several projects. For each project i, it has a pure profit Pi and a minimum capital of Ci is needed to start the corresponding project. Initially, you have W capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
To sum up, pick a list of at most k distinct projects from given projects to maximize your final capital, and output your final maximized capital.
 
例子
>> Input: k=2, W=0, Profits=[1,2,3], Capital=[0,1,1].
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
             After finishing it you will obtain profit 1 and your capital becomes 1.
             With capital 1, you can either start the project indexed 1 or the project indexed 2.
             Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
             Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.


---

**分析**
>> 刚刚开始看的时候以为是动态规划问题类似背包问题，但是仔细读题，这里说道得到的利润可以继续叠加到资本，说明这不是一个动态规划问题。
接着考虑使用贪心算法 主要用到了优先队列，我们要使得利益最大化就要遵循一下几个原则：
1.你现在拥有的资本越多，最终的资本就越多。
2.以合理的的方式处理任何可行的项目即P[i] > 0会增加资本W。
3.任何项目P[i] = 0是无用的，应立即去掉。
4.有钱的时候先做最赚钱的。


现在我们考虑每个项目，在每个阶段，将项目分为两类：
“可做的”：将C[i] <= W（P[i]存在的priority_queue<int> low）
“暂时不可做（以后可能有了资本可以做的）”：有C[i] > W（存储(C[i], P[i])在multiset<pair<int,int>> high）

按照下面的顺序进行：
1.首先从low（low.top()）开始做最赚钱的项目，然后更新资本W += low.top()。
2.把那些以前的high中暂时不可做，现在可以了的(即满足C[i] <= W)移动到low中。
3.重复第2步和第3步，直到我们达到最大的k项目或没有更多可行的项目。

---


**AC代码**

```c
int findMaximizedCapital(int k, int W, vector<int>& P, vector<int>& C) {
    priority_queue<int> low;      
    multiset<pair<int,int>> high; 
    
    for (int i = 0; i < P.size(); ++i) {
        if(P[i] > 0) if (C[i] <= W) low.push(P[i]); else high.emplace(C[i], P[i]);
    }

    while (k-- && low.size()) { 
        W += low.top(), low.pop(); // greedy to work on most profitable first
        for (auto i = high.begin(); high.size() && i->first <= W; i = high.erase(i)) low.push(i->second);
    }
    return W;
}
```