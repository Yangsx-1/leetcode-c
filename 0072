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
