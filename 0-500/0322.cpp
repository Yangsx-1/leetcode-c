// finished in 2024.2.4
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        for (int x = 0; x < coins.size(); ++x) {
            int coin = coins[x];
            for (int y = 1; y <= amount; ++y) {
                if (y >= coin) {
                    dp[y] = min(dp[y], dp[y-coin]+1);
                }
            }
        }
        return dp[amount] < INT_MAX-1 ? dp[amount] : -1;
    }
};