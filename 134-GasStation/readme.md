# Leetcode 134. Gas Station 解题报告
---

**题目**
>There are N gas stations along a circular route, where the >amount of gas at station i is gas[i].
>
>You have a car with an unlimited gas tank and it costs cost[i] >of gas to travel from station i to its next station (i+1). You >begin the journey with an empty tank at one of the gas >stations.
>
>Return the starting gas station's index if you can travel >around the circuit once, otherwise return -1.
>
>Note:
>The solution is guaranteed to be unique.

---

**分析**
>最简单的做法就是遍历一次每个作为起点,复杂度是O(n^2).

现在考虑只需要遍历一次的方法
经过每个油站对车来讲就是2中情况加了油或者耗了油,这可以用gas[i]-cost[i]来反映.于是我们构造数组detaGas[i] = gas[i] - cost[i].表示经过一个油站对油量的影响.
现在考虑从油站i出发一直到油站p-1油箱的油一直是>=0, 到了p油箱油<0,
即:sum ＝　detaGas[i]+detaGas[i+1]+detaGas[i+２]...+detaGas[p-1]>=０
sum ＝　detaGas[i]+detaGas[i+1]+detaGas[i+２]...+detaGas[p]<０

那么可以知道detaGas[i]>=0, 如果从i+1到p-1之间出发更不可能到p,因为少加了i的油.那么我们只需要考虑从p出发就好了,这样只需要遍历一次数组就可以得到答案.

假设数组daraGas被分为3段
sum1 = detaGas[0]+detaGas[1]+.....+detaGas[i] <　0;
sum2 = detaGas[i+1]+detaGas[i+2]+.....+detaGas[k] < 0;
sum3 = detaGas[k+1]+detaGas[1]+.....+detaGas[l-1] >= 0;
(一定最后一段的前面的和都是小于零的)

从k+1能回来的条件是 要能从0走到k,此时可以借助从k+1到l-1攒下的油,即满足 sum3+sum1+sum2 >= 0就可以回来.

---

**AC代码**

```c
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int l = gas.size();
        if (l <= 0) return -1;
        
        int s = 0;
        int curSum = 0;
        int b = 0 ,total = 0;
        for (int i = 0; i < l; ++i) {
            curSum += (gas[i] - cost[i]);
            total += (gas[i] - cost[i]);
            
            if (curSum >= 0) {
                
            } else {
                b = i+1;
                curSum = 0;
            }
        }
        
        if (total >= 0) return b;
        else return -1;
    }
};
```