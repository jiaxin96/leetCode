import java.util.*;

public class Main {
	public static void main(String[] args) {
		Solution s = new Solution();
		char[][] board = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
		s.solveSudoku(board);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; ++j) {
				System.out.printf("%c ", board[i][j]);

			}
				System.out.printf("\n");
		}
	}
}
class Solution {
	boolean isOk = true;
	public void solveSudoku(char[][] board) {

		get_ans(0,0,board);

	}


	void get_ans(int r, int c, char[][] board) {

		for (int i = c; i < 9; ++i) {
			if (board[r][i] == '.') {
				isOk = false;
				for (int k = 1; k <= 9; ++k) {

					if (check_canput(r,c,k,board)){
						put_num(i,j,num, board);
						if (isOK || (r==8&&r==c&&check_pass()) ) {
							isOk = true;
							return;
						}
						if (r<9) {
							if (!isOk)
								get_ans(r+1,c,board);
						}
						else if (c<9) {
							if (!isOk)
								get_ans(r,c+1,board);
						}
						if (!isOk)
							recover_num(i,j, board);
					}
					
				}
			}
		}
		
	}

	void put_num(int row, int col, int num, char[][] board) {
		board[row][col] = (num+"")[0];
	}

	boolean check_pass(char[][] board) {
		// 横向
		HashSet<Character> nums = new HashSet<Character>();
		for (int i = 0; i < 9; ++i) {
			nums.clear();
			for (int j = 0; j < 9; ++j) {
				if (board[i][j]>='0' && board[i][j]<='9') {
					nums.add(board[i][j]);
				}
			}
			if (nums.size() != 9) {
				return false;
			}
		}
		// 纵向
		for (int i = 0; i < 9; ++i) {
			nums.clear();
			for (int j = 0; j < 9; ++j) {
				if (board[j][i]>='0' && board[j][i]<='9') {
					nums.add(board[j][i]);
				}
			}
			if (nums.size() != 9) {
				return false;
			}
		}


		// 9个方块
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				nums.clear();
				for (int r = i*3; r < (i+1)*3; ++r) {
					for (int c = j*3; c < (j+1)*3; ++c) {
						if (board[r][c]>='0' && board[r][c]<='9') {
							nums.add(board[r][c]);
						}
					}
				}
				if (nums.size() != 9) {
					return false;
				}
			}
		}


		return true;
	}
	boolean check_canput(int row, int col,int num, char[][] board) {
		HashSet<Character> nums = new HashSet<Character>();
		int count = 0;
		// 横向
		nums.clear();
		for (int i = 0; i < 9; ++i) {
			if (board[row][i]>='0' && board[row][i]<='9') {
				nums.add(board[row][i]);
			}
		}
		count =nums.size();
		if (count != 9) {
			nums.add((num+"")[0]);
			if (count != nums.size()) return true;
		} else {
			return false;
		}
		// 纵向
		nums.clear();
		for (int i = 0; i < 9; ++i) {
			if (board[i][col]>='0' && board[i][col]<='9') {
				nums.add(board[i][col]);
			}
		}
		count =nums.size();
		if (count != 9) {
			nums.add((num+"")[0]);
			if (count != nums.size()) return true;
		} else {
			return false;
		}

		int i = row/3;
		int j = col/3;

		nums.clear();
		for (int r = i*3; r < (i+1)*3; ++r) {
			for (int c = j*3; c < (j+1)*3; ++c) {
				if (board[r][c]>='0' && board[r][c]<='9') {
					nums.add(board[r][c]);
				}
			}
		}
		if (nums.size() != 9) {
			return false;
		}

		return false;
	}

	void recover_num(int row, int col, char[][] board) {
		board[row][col] = '.';
	}


}