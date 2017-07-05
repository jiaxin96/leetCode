public class Main {

	public static void main(String[] args) {
		Solution s = new Solution();

		System.out.println(s.isSubsequence("abc", "ahbgdc"));
	}

}
// "abc"
// "ahbgdc"


class Solution {
    public boolean isSubsequence(String s, String t) {
        if (s == null || s.length() == 0) return true;
        for (int i = 0; i < t.length(); i += 1) {
            if (t.charAt(i) == s.charAt(0)) return isSubsequence(s.substring(1), t.substring(i + 1));
        }
        return false;
    }
}