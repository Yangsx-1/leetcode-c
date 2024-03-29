// finished in 2024.1.28
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size()+1, n = p.size()+1;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 1;
        for (int j = 1; j < n; ++j) {
            if(p[j-1] == '*') dp[0][j] = dp[0][j-2];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    if (s[i-1] == p[j-2] || p[j-2] == '.') {
                        dp[i][j] = dp[i][j-2] | dp[i-1][j-2] | dp[i-1][j];
                    } else {
                        dp[i][j] = dp[i][j-2];
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};