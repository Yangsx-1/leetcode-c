// finished in 2024.2.5
// 使用动态规划加单调队列，使用递减队列，保证队头是前i-k个中的最大值
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        deque<int> q;
        q.push_back(0);
        for (int i = 1; i < n; ++i) {
            while (!q.empty() && q.front() < i-k) {
                q.pop_front();
            }
            dp[i] = dp[q.front()] + nums[i];
            while (!q.empty() && dp[q.back()] <= dp[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return dp[n-1];
    }
};