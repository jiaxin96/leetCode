
class Solution {
	public String removeKdigits(String num, int k) {

		StringBuffer str = new StringBuffer("");

		int pos = -1;

		for (int i = 0; i < num.length(); ++i) {
			while (str.length() > 0 && k > 0 && num.charAt(i) < str.charAt(str.length()-1)) {
				k--;
				str.deleteCharAt(str.length() - 1);
			}
			if (str.length() == 0 && num.charAt(i) == '0') {

			} else {
				str.append(num.charAt(i));
			}
		}


		if (k >= str.length()) return "0";

		while (k > 0) {
			k--;
			str.deleteCharAt(str.length() - 1);
		}

		// str.delete(0, k);
		return str.length() == 0 ? "0" : str.toString();
	}
}

        // StringBuilder sb = new StringBuilder();
        // for(char c : num.toCharArray()) {
        //     while(k > 0 && sb.length() != 0 && sb.charAt(sb.length() - 1) > c) {
        //         sb.setLength(sb.length() - 1);
        //         k--;
        //     }
        //     if(sb.length() != 0 || c != '0') sb.append(c);  // Only append when it is not leading zero
        // }
        // if(k >= sb.length()) return "0";
        // sb.setLength(sb.length() - k);  // use all remaining k
        // return sb.toString();
public class Main {
	public static void main(String[] args) {
		Solution ss = new Solution();
		System.out.println(ss.removeKdigits("112", 1));
	}
}