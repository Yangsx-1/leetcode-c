// finished in 2024.1.25
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (const auto &it : nums) {
            sum += it;
        }
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<int> dp(target+1);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] |= dp[j-nums[i]];
                if (j == target && dp[j] == 1) return true;
            }
        }
        return false;
    }
};