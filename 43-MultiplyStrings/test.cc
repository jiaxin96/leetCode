/**
 * File: e:\code\leetCode\43-MultiplyStrings\test.cc
 * Project: e:\code\leetCode
 * Created Date: Monday, August 7th 2017, 3:32:13 pm
 * Author: JX
 * -----
 * Last Modified: Mon Aug 07 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a = 12;
    istringstream iss(a);
    // iss << 12;
    iss >> a;
    std::cout << a;
    // iss << 123;
    iss >> a;
    std::cout << a;
    return 0;
}
