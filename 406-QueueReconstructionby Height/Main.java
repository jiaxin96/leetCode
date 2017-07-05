import java.util.*;
public class Main {

	public static void main(String[] args) {
		Solution s = new Solution();		
	}
}



class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (x, y) -> x[0] != y[0] ? y[0] - x[0] : x[1] - y[1]);
        LinkedList<int []> ans = new LinkedList<>();
        for (int[] i : people) {
        	ans.add(i[1],i);
        }

        return ans.toArray(new int[1][1]);
    }
}