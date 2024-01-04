// finished in 2024.1.4
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxsize = 0;
        while (left < right) {
            int s;
            if (height[left] <= height[right]) {
                s = (right - left) * height[left];
                left++;
            } else {
                s = (right - left) * height[right];
                right--;
            }
            if (s > maxsize) maxsize = s;
        }
        return maxsize;
    }
};