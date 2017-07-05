import java.util.*;


public class Main {
	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.canIWin(3,5));		
	}
}

/*
表示考虑选择i的情况，用mask = 1 << i，如果mask和visited进行与运算，
如果等于0说明当前的visited没有被访问过，就可以考虑这个i的情况，如果要选的这个i大于target，
不傻的这个人就会选择i因为肯定能赢啦～还有种情况自己能赢，就是对方输了，即：canWin(target – i, mask | visited) == false，
（mask | visited表示把i那位也标记为1～）这个时候把visited情况存起来并且return true，
表示赢了～如果所有数字都遍历完还是没有return true，
那就最后return false～return false之前不要忘记把当前状态存储起来～也就是m[visited] = false;
*/
class Solution {
    
    HashMap<Integer, Boolean> visited = new HashMap<>();

    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if ((1+maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal) return false;

        return getans(maxChoosableInteger, desiredTotal, 0);
    }

    boolean getans(int max, int tar, int cur) {

        if (visited.size() !=0 && visited.containsKey(new Integer(cur))) return visited.get(cur);
        for (int i = 0; i < max; ++i) {
            int mask = (1<<i);
            if ( ( (mask & cur) == 0  ) && ( (i+1) >= tar || getans(max, tar - (i+1), mask|cur) == false ) ) {
                visited.put(cur, true);
                return true;
            }
        }

        visited.put(cur,false);
        return false;
    }
}