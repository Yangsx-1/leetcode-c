// finished in 2024.2.4
class Solution {
public:
    pair<int, int> count_onezero(const string& s) {
        int z = 0, o = 0;
        for (auto const& it : s) {
            if (it == '0') {
                ++z;
            } else {
                ++o;
            }
        }
        return {z, o};
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (const string& s : strs) {
            auto [c0, c1] = count_onezero(s);
            for (int x = m; x >= c0; --x) {
                for (int y = n; y >= c1; --y) {
                    dp[x][y] = max(dp[x][y], dp[x-c0][y-c1]+1);
                }
            }
        }
        return dp[m][n];
    }
};