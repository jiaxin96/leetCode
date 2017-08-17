/**
 * File: e:\code\leetCode\0-test\testSplitStr.cc
 * Project: e:\code\leetCode
 * Created Date: Wednesday, August 16th 2017, 1:05:07 pm
 * Author: JX
 * -----
 * Last Modified: Wed Aug 16 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

/* strtok example */
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char *str = "a,b,c,d*e";
//     const char *split = ",";
//     char *p;
//     p = strtok(str, split);
//     while (p != NULL)
//     {
//         printf("%s\n", p);
//         p = strtok(NULL, split);
//     }

//     getchar();
//     return 0;
// }
/* strtok example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="- This, a sample string.";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }
  return 0;
}