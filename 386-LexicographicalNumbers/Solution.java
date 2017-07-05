public class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> l = new LinkedList<Integer>();
        getans(l, 1, new Integer(n).toString().length(), n, 0);
        return l;
    }

    public void getans(List<Integer> l, int s, int len, int n, int baseNum) {
    		if (s > len) return;
    		for (int i = 0; i <= 9; ++i) {
    			if (baseNum + i <= n && baseNum + i != 0) {
    				l.add(baseNum + i);
    				getans(l, s+1, len, n, (baseNum+i)*10);
    			}
    		}
    }
}