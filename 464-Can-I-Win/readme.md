# Leetcode 464 can i win
<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script>

---
**描述**

>>In the "100 game," two players take turns adding, to a rWhat if we change the game so that players cannot re-use integers? 
For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.
Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally. 
You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300. 
Example


---
**解释**
>>
	题目先说了一个100游戏，意思是每个人从1道到10轮流报数，看谁先总数累计到100就算谁赢.然后提出了一个更加一般的游戏规则，给定一个数字作为能报的最大数字，给定一个数字作为最终的目标也就是累计和，看谁能先报数报到总计的数字和超过或者等于这个目标和，就算谁嬴。现在给定这两个数字，让你判断第一个报数的人能不能赢，如果2个玩家都足够聪明也就是每次都是选择最优的数字去报数。

---

**分析**
	首先我们考虑一个比较简单的问题，（其实这里已经用到动态规划的思想即找子问题的解），最大的数字就是1，目标就是n，那么n是偶数的时候第一个人一定会输
	，如果最大数字是2，目标是n，那么这个问题取决于第一个人第一次选择的数字，
	如果是1，那么结果和最大数字是2，目标是n-1的时候相反，
	如果第一个人第一次选的是2，那么结果和最大数字是2，目标是n-2相反，
	于是根据这个思路，我们可以得到一个递归的表达式，
	win[k，n]表示如果可以选择的最大数字是k，目标是n的时候第一个人能赢还是输，
	那么win[k,n]=!(win[k,n-k]|win[k,n-(k-1)]|win[k, n-(k-2)]|win[k, n-(k-...)|...|win[k, k+1]]) , 当k<n。 当k>=n时，win[k,n] = True.但是这样写运算超时,有没有可以优化的地方呢?
	顺着这个思路,考虑使用一个32位visited的每一位记录选过的数字,用一个用map标记当前情况在map表中是否存在，存在的话结果保存在map里面,如果我们发现这个visited也就是这个数字选择的情况已经被保存过了，就直接返回在map里面保存的结果,如果没有就从1开始选直到最大可选值,并且每次减小目标值,递归调用.
	。
---

**AC代码**
```c
class Solution {
private:
    int maxn;
    map<int, bool> m;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxn = maxChoosableInteger;
        if(maxn >= desiredTotal) return true;
        if((1 + maxn) * maxn / 2 < desiredTotal) return false;
        return canWin(desiredTotal, 0);
    }
    bool canWin(int target, int visited) {
        if(m.find(visited) != m.end()) return m[visited];
        for(int i = 1; i <= maxn; i++) {
            int mask = (1 << i);
            if((mask & visited) == 0 && (i >= target || canWin(target - i, mask | visited) == false)) {
                m[visited] = true;
                return true;
            }
        }
        m[visited] = false;
        return false;
    }
};
```