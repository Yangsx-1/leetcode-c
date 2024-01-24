class Solution {
public:
    int minDistance(string word1, string word2) {
        string w1 = word1, w2 = word2;
        vector<vector<int>> dp(w1.size() + 1, vector<int>(w2.size() + 1));
        for (int i = 0; i < dp.size(); i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j < dp[0].size(); j++)
        {
            dp[0][j] = j;
        }
        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j < dp[i].size(); j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if (w1[i - 1] == w2[j - 1])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }
        return dp[w1.size()][w2.size()];
    }
};

// finished in 024.1.24
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size()+1, n = word2.size()+1;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i < n; ++i) {
            dp[0][i] = i;
        }
        for (int x = 1; x < m; ++x) {
            for (int y = 1; y < n; ++y) {
                if (word1[x-1] == word2[y-1]) {
                    dp[x][y] = min(dp[x-1][y]+1, min(dp[x][y-1]+1, dp[x-1][y-1]));
                } else {
                    dp[x][y] = min(dp[x-1][y], min(dp[x][y-1], dp[x-1][y-1]))+1;
                }
            }
        }
        return dp[m-1][n-1];
    }
};