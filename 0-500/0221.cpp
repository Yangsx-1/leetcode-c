// finished in 2024.1.25
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxans = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int x = 0; x < m; ++x) {
            if (matrix[x][0] == '1') {
                dp[x][0] = 1;
                if (dp[x][0] > maxans) maxans = dp[x][0];
            } 
        }
        for (int x = 0; x < n; ++x) {
            if (matrix[0][x] == '1') {
                dp[0][x] = 1;
                if (dp[0][x] > maxans) maxans = dp[0][x];
            } 
        }
        for (int x = 1; x < m; ++x) {
            for (int y = 1; y < n; ++y) {
                if (matrix[x][y] == '1') {
                    dp[x][y] = min(dp[x-1][y-1], min(dp[x-1][y], dp[x][y-1]))+1;
                    if (dp[x][y] > maxans) maxans = dp[x][y];
                }
            }
        }
        return maxans * maxans;
    }
};