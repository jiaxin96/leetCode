/**
 * File: e:\code\leetCode\166-FractiontoRecurringDecimal\Solution.cc
 * Project: e:
 * Created Date: Tuesday, October 10th 2017, 10:23:33 pm
 * Author: JX
 * -----
 * Last Modified: Wed Oct 11 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // special cases
        if(numerator == 0)
            return "0";
        string ret = "";
        // type conversion in case of INT_MIN
        long long n = numerator;
        long long d = denominator;
        // sign
        int sign = 1;
        
        // 整数部分是否存在
        bool digit = false;

        // 同号为正 异号为负
        if((n<0) ^ (d<0))
            sign = -1;
        n = abs(n);
        d = abs(d);
        unordered_map<long long, int> m;  // numerator --> position
        while(true)
        {
            // 如果是一个纯小数
            if(n < d)
            {
                // 小数部分出现的时候
                if(digit == false)
                {
                    // 没有整数部分的时候
                    if(ret == "")
                        ret = "0.";
                    else
                        ret += ".";
                    digit = true;
                }
                n *= 10;
            }

            // 余数
            int r = n - n/d*d;
            
            // 能整除直接得到答案
            if(r == 0)
            {
                ret += to_string(n/d);
                if(sign == -1)
                    ret = "-" + ret;
                return ret;
            }
            else
            {
                // 小数部分
                if(digit == true)
                {
                    // 被除数没有出现过
                    if(m.find(n) == m.end())
                    {
                        // 得到本次的商
                        ret += to_string(n/d);
                        // 商的位置
                        m[n] = ret.size()-1;
                    }
                    else
                    {
                        // 没有重复的商的个数
                        int pos = m[n];
                        ret = ret.substr(0, pos) + "(" + ret.substr(pos) + ")";
                        if(sign == -1)
                            ret = "-" + ret;
                        return ret;
                    }
                }
                else
                {
                    ret += to_string(n/d);;
                }
                // 新的被除数
                n = r;
            }
        }
    }
};