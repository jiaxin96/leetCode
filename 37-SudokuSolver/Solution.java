import java.util.HashSet;
import java.util.HashSet;
import java.util.LinkedList;

/**
 * File: e:\code\leetCode\37-SudokuSolver\Solution.java
 * Project: e:\code\leetCode
 * Created Date: Monday, July 31st 2017, 11:34:45 pm
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

public class Solution {

    public static void main(String[] args) {
        
    }
    public void solveSudoku(char[][] board) {
        LinkedList<cor> poss = getEmptyPos(board);
        for(cor p : poss) {
            dfs(p.getX(), p.getY(),board);
        }
    }

    public LinkedList<cor> getEmptyPos(char[][] board) {
        LinkedList<cor> ans = new LinkedList<>();
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == '.') {
                    ans.add(new cor(i,j));
                }
            }
        }
        return ans;
    }
    public HashSet<Integer> getPutNums(int r, int c, char[][]board) {
        HashSet<Integer> ans_complement = new HashSet<>();
        //横向
        for (int i = 0; i < 8; ++i) {
            if (board[r][i] != '.') {
                ans_complement.add(board[r][i]-'0');
            }
        }
        //纵向
        for (int i = 0; i < 8; ++i) {
            if (board[i][c] != '.') {
                ans_complement.add(board[i][c]-'0');
            }
        }
        // 方块
        for(int i = 3*(r/3); i < 4*(r/3); ++i) {
            for(int j = 3*(r/3); j < 4*(r/3); ++j) {
                if (board[i][j] != '.') {
                    ans_complement.add(board[i][j] - '0');
                }
            }
        }
        HashSet<Integer> ans = new HashSet<>();
        for (int i = 0; i < 8; ++i) {
            ans.add(i+1);
        }
        
        ans.removeAll(ans_complement);
        return ans;
    }
    public void dfs(int count, char[][] board) {
        if (count > 81) return;
        int r = (count-1) / 9;
        int c = count - 9*r - 1;
        
        
    }

    class cor {
        int x;
        int y;
        public cor(int x, int y) {
            this.x = x;
            this.y = y;
        }
        public int getX() {
            return x;
        }
        public int getY() {
            return y;
        }
        public void setX(int x) {
            this.x = x;
        }
        public void setY(int y) {
            this.y = y;
        }
    }
}