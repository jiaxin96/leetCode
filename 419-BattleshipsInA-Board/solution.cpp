// Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

// You receive a valid board, made of only battleships or empty slots.
// Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
// At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
#include <vector>
using namespace std;
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
    	bool rowvalid = true;
        // row 
        int pre = -2;
        int pos = 0;
        int rcount = 0;
        for (int i = 0; i < board.size(); ++i) {
        		for (int j = 0; j < board[i].size(); ++j)
        		{
        			if (board[i][j] == 'X') pos = j;
        			else continue;
        			if (pos - pre <= 1) {
        				rowvalid = false;
        				break;
        			} else {
        				pre = pos;
        				rcount++;
        			}
        		}
        }
        bool colvalid = true;
        pre = -2;
        pos = 0;
        int ccount = 0;
        for (int i = 0; i < board[0].size(); ++i) {
        		for (int j = 0; j < board[j][i]; ++j) {
        			if (board[j][i] == 'X') pos = j;
        			else continue;
        			if (pos - pre <= 1) {
        				colvalid = false;
        				break;
        			} else {
        				pre = pos;
        				ccount++;
        			}
        		}
        }
        if (rowvalid) return rcount;
        else if (colvalid) return ccount;
        else return 0;
    }
};