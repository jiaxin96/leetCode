# Leetcode 738. Monotone Increasing Digits

---

**题目**
Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

---

**例子**
1. Input: N = 10
   Output: 9
2. Input: N = 1234
   Output: 1234
3. Input: N = 332
   Output: 299

---

**分析**

>> 题目要求构造一个小于等于原来的数字的数字，并且新数字从高位到低位的每个位的数要非递减（x <= y， x为高位y为低位），从例子中我们可以看到，
   如果原来的数就是一个非递减的数字，那么我们直接使用原数字即可，如果原来的不是可以想象我们只要取原数字的递增部分，然后对于剩下的部分，填充9即可，
   这样处理会留下一些小问题，例如332，会填为339，所以我们还需要找到一个点在填充9后将前面递增部分的某一个值减1后，剩下的部分填9，在332这个例子中是第一个3减1为2，后面填9，即得299.
   问题就是如何寻找这个需要减1的位置，利用贪心的想法，每次从后向前遍历，只要发现N[i]<N[i-1]，就把N[i-1]-1，这样可以找到第一个非递减的点，并且将他减1，后面的值就只需要补9即可。例如332，那么第二个3首先会被减1，因为这个值如果不减将来得到的数字从他向后都是9，一定比原来的数字不会小，所以减1，由此会使得第一个数字也减1，记录下第一个位置，后面的都赋值为9即可。

---

**AC代码**

```c
class Solution
{
  public:
    int monotoneIncreasingDigits(int N)
    {
        string n_str = to_string(N);

        int marker = n_str.size();
        for (int i = n_str.size() - 1; i > 0; i--)
        {
            if (n_str[i] < n_str[i - 1])
            {
                marker = i;
                n_str[i - 1] = n_str[i - 1] - 1;
            }
        }

        for (int i = marker; i < n_str.size(); i++)
            n_str[i] = '9';

        return stoi(n_str);
    }
};
```