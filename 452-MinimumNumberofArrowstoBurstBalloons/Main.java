class Solution {
    public int findMinArrowShots(int[][] points) {
    if(points==null || points.length==0) return 0;
    //优先按照起点位置排序，然后按照结束位置排序
    Arrays.sort(points, (int[] x ,int[] y) -> x[0] == y[0] ? x[1] - y[1] : x[0] -y[0]);
    int count = 1;
    int arrowLimit = points[0][1];
    //贪心法，基于上一个箭，记录当前能够射穿的所有
    for(int i=1;i<points.length;i++) {
        if(points[i][0]<=arrowLimit) {
            arrowLimit=Math.min(arrowLimit, points[i][1]);
        } else {
            count++;
            arrowLimit=points[i][1];
        }
    }
    return count;
    }
}


public class Main {
	public static void main(String[] args) {
		
	}
}