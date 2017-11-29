/**
 * File: e:\code\leetCode\37-SudokuSolver\Solution.java
 * Project: e:\code\leetCode
 * Created Date: Monday, July 31st 2017, 11:34:45 pm
 * Author: JX
 * -----
 * Last Modified: Wed Aug 02 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 *
 *实验中使用JAVA会超时
 * 改为C++即可
 *
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

public class Solution {

    public static void main(String[] args) {
        
    }
    public boolean isOk = false;
    public void solveSudoku(char[][] board) {
        dfs(1,board);
    }

    public boolean canPut(int r, int c, int num, char[][] board) {
        char aim = String.valueOf(num).charAt(0);
        //横向
        for (int i = 0; i < 8; ++i) {
            if (board[r][i] == aim) {
                return false;
            }
        }
        //纵向
        for (int i = 0; i < 8; ++i) {
            if (board[i][c] == aim) {
                return false;
            }
        }
        // 方块
        for(int i = 3*(r/3); i < 4*(r/3); ++i) {
            for(int j = 3*(r/3); j < 4*(r/3); ++j) {
                if (board[i][j] == aim) {
                return false;
                }
            }
        }
        return true;
    }
    
    public boolean dfs(int count, char[][] board) {
        if (count > 81) {
            return true;
        }
        int r = (count-1) / 9;
        int c = count - 9*r - 1;
        if (board[r][c] == '.') {
            for (int i = 1; i <= 9; ++i) {
                if (canPut(r , c, i, board)) {
                    board[r][c] = String.valueOf(i).charAt(0);
                    if (dfs(count+1, board)) {
                        return true;
                    } else {
                        board[r][c] = '.';
                    }
                }
            }
        } else {
            dfs(count+1, board);            
        }
        
    }
}
