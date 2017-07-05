public class Main {
	public static void main(String[] args) {
		Solution a = new Solution();

	}
}

class Solution {
	boolean can;
	public boolean canFinish(int numCourses, int[][] prerequisites) {
		int [] visited = new int[numCourses];
		int [][] MyMap = new int[numCourses][numCourses];
		for (int i = 0; i < numCourses; ++i) {
			visited[i] = 0;
			for (int j = 0; j < numCourses; ++j) {
				MyMap[i][j] = 0;
			}
			MyMap[i][i] = 1;
		}
		for (int[] i : prerequisites) {
			MyMap[i[0]][i[1]] = 1;
		}

		int ansIndex = 0;

		can = true;

		for (int i = 0; i < numCourses; ++i) {
			if (visited[i] == 0) {
				
				DFS(visited, i, ansIndex, MyMap, numCourses);
			
			}
		}

		return can;

	}

	public void DFS(int [] visited, int curr, int ansIndex, int[][] MyMap, int numCourses) {
		visited[curr] = 1; // 看过一次


		for (int i = 0; i < numCourses; ++i) {
			if (MyMap[curr][i] == 1 && visited[i] == 0 && i != curr) {
				DFS(visited, i, ansIndex, MyMap, numCourses);
			} else if (MyMap[curr][i] == 1 && visited[i] == 1 && i != curr) {
				can = false;
			}
		}
		visited[curr] = 2; // 子孙看完
	}


}
