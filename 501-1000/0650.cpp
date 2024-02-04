// finished in 2024.2.4
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1);
        for (int i = 0; i < dp.size(); ++i) {
            dp[i] = i;
        }
        dp[1] = 0;
        for (int i = 2; i < dp.size(); ++i) {
            int tmp = i * 2;
            if (tmp < dp.size()) {
                dp[tmp] = min(dp[tmp], dp[tmp / 2]+2);
            } else {
                break;
            }
            while (tmp < dp.size()) {
                int id = tmp+i;
                if (id < dp.size()) {
                    dp[id] = dp[tmp]+1;
                } else {
                    break;
                }
                tmp = id;
            }
        }
        return dp[n];
    }
};