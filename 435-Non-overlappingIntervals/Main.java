
public class Main {
	public static void main(String[] args) {
		
	}
}



/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */

import java.util.*;

class Solution {
    public int eraseOverlapIntervals(Interval[] intervals) {
        Arrays.sort(intervals, (a,b) -> {a.start == b.start ? a.end - b.end : a.start - b.start});
        int count=0,j=0;
        // 贪心法，如果上一个位置j和当前位置i冲突了，那么进行判断，如果当前位置的末尾小于上一个边界的末尾，那么删除上一个位置（因为覆盖的更少，每步选择最有可能不造成重复的），反之如果当前位置尾部覆盖的更多，那么就删除i的位置。删除的方式通过控制j的取值进行
        for(int i=1;i<intervals.length;i++) {
            if(intervals[j].end>intervals[i].start){
                j=intervals[i].end<intervals[j].end?i:j;
                count++;
            }else
            //没有重复
                j=i;
        }
        return count;
    }
}
