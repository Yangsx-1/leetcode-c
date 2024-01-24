// finished 2024.1.24
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n));
        dp[0][0] = nums[0];
        dp[1][0] = nums[0];
        int maxans = nums[0];
        for (int i = 1; i < n; ++i) {
            int curr = nums[i];
            dp[0][i] = max(curr, max(dp[0][i-1]*curr, dp[1][i-1]*curr));
            dp[1][i] = min(curr, min(dp[0][i-1]*curr, dp[1][i-1]*curr));
            if (dp[0][i] > maxans) maxans = dp[0][i];
        }
        return maxans;
    }
};