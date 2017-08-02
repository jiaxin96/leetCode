/**
 * File: e:\code\leetCode\37-SudokuSolver\java通过的解法.java
 * Project: e:\code\leetCode
 * Created Date: Tuesday, August 1st 2017, 10:10:50 pm
 * Author: JX
 * -----
 * Last Modified: Tue Aug 01 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

int size = 9;
int subsize = 3;

public boolean solveSukodu(char[][] board) {
    return helper(board, 0, 0);
}



private boolean helper(char[][] board, int row, int col) {
    if (row >= size) {
        return true;
    }
    if (!isNumberValid(board, row, col)) {
        return false;
    }
    if (board[row][col] == '.') {
        char c = '1';
        for (; c <= '9'; c++) {
            board[row][col] = c;
            if (!helper(board, row, col)) {
                board[row][col] = '.';
            } else {
                break;
            }
        }
        if (c > '9') {
            return false;
        }
    } else {
        col++;
        if (col >= size) {
            row++;
            col = 0;
        }
    }
    return helper(board, row, col);
}



private boolean isNumberValid(char[][] board, int row, int col) {
    char c = board[row][col];
    for (int i = 0; i < size; i++) {
        if (board[i][col] != '.' && i != row &&
            board[i][col] == c) {
            return false;
        }
    }
    for (int i = 0; i < size; i++) {
        if (board[row][i] != '.' && i != col &&
            board[row][i] == c) {
            return false;
        }
    }
    int m = row / subsize * subsize;
    int n = col / subsize * subsize;
    for (int i = 0; i < subsize; i++) {
        for (int j = 0; j < subsize; j++) {
            if (board[i + m][j + n] != '.' &&
                ((i + m) != row && (j + n) != col) &&
                board[i + m][j + n] == c) {
                return false;
            }
        }
    }
    return true;
}