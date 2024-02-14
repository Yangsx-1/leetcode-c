// finished in 2024.2.13
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int max = INT_MIN, min = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < max) {
                right = i;
            } else {
                max = nums[i];
            }
        }
        for (int i = nums.size()-1; i >= 0; --i) {
            if (nums[i] > min) {
                left = i;
            } else {
                min = nums[i];
            }
        }
        return left == right ? 0 : right - left + 1;
    }
};