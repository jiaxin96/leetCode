public class Main {
	public static void main(String[] args) {
		
	}
}

class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        int left = 1, right = height.length;
        max = (right-left)*(Math.min(height[right-1], height[left-1]));
        while (left < right) {
        	if (height[right-1] < height[left-1]) {
        		right--;
        	} else {
        		left++;
        	}
        	max = max  >= (right-left)*(Math.min(height[right-1], height[left-1])) ? max : (right-left)*(Math.min(height[right-1], height[left-1]));
        }
        return max;
    }
}