public class Main {
	public static void main(String[] args) {
		Solution s = new Solution();
		String str = s.getPermutation(3,5);
		System.out.println(str);
	}
}


class Solution {
    
	int record = ~0;

    int factorial(int n) {
    	if (n == 0) return 1;
    	int ans = 1;
    	for (int i = 1; i <= n; ++i) {
    		ans *= i;
    	}
    	return ans;
    }

    int getnext(int num) {
    	
    	int count = 0;

    	for (int i = 1; i <= 32; ++i) {
    		int mask = 1 << (i - 1);
    		if ( (mask & record) == 1 ) {
    			if (num == 0) {
    				record = (~(1<<(i-1))) & record;
    				return i;
    			}
    			count++;
    		}

    		if (count == num) {
    			record = (~(1<<(i-1))) & record;
    			return i;
    		}

    	}

    	return 0;
    }

    public String getPermutation(int n, int k) {
        
        record = ~0;

        String ans = "";
        int t = k;
        for (int i = n-1; i >= 0; --i) {
        	int f = factorial(i);
        	int r = t % f;
        	int q = t / f;
        	t = r;
        	ans = ans + ("" + getnext(q));
        }
        return ans;
    }
}