public class Main {

	public static void main(String[] args) {
		
	}

}
/*
利用XOR的性质，a^b = c, 则有 a^c = b，且 b^c = a;
所以每次从高位开始，到某一位为止，所能获得的最大的数。
设置变量mask用来表示能形成的值，
每一次将mask和其他的num相与得到的值加入set，
表示在当前这一位上，数组里有这么多prefix。

假定在某一位上的任意两数xor能得到的最大值是tmp,
那么他一定满足a(xor)b = tmp,其中set.contains(a) && set.contains(b). 
所以，我们只需要判断b(xor)tmp的结果是不是在当前这一位下的set内，
就可以知道这个tmp能不能又这个set中的任意两个数组成。
*/
class Solution {
    public int findMaximumXOR(int[] nums) {
        int max = 0, mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            HashSet<Integer> set = new HashSet<Integer>();
            for (int num : nums) {
                set.add(num & mask); // reserve Left bits and ignore Right bits
            }
            
            
            int tmp = max | (1 << i); // in each iteration, there are pair(s) whoes Left bits can XOR to max
            for (int prefix : set) {
                if (set.contains(tmp ^ prefix)) {
                    max = tmp;
                    break;
                }
            }
        }
        return max;
    }
}