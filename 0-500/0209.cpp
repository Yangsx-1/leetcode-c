// finished in 2024.2.10
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen = INT_MAX;
        int sum = nums[0];
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (sum < target) {
                ++right;
                if (right < nums.size()) sum += nums[right];
                else break;
            } else {
                while (left <= right && sum >= target) {
                    if (right - left + 1 < minlen) {
                        minlen = right - left + 1;
                        if (minlen == 1) return 1;
                    }
                    sum -= nums[left];
                    ++left;
                }
                if (left > right) {
                    right = left;
                    sum = nums[right];
                }
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};