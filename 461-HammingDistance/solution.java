public class solution {
    public static int hammingDistance(int x, int y) {
        int count = 0;
        int k = x^y;
        while (k > 0) {
        	int t = k&1;
        	if (t == 1) count++;
        	k >>= 1;
        }
        return count;
    }
    public static void main(String[] args) {
    		System.out.println(hammingDistance(1,4));
    }
}