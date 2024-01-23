class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }
        int maxlen = 1;
        int begin = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i < n; ++i) {
                int j = i + l - 1;
                if (j >= n) {
                    break;
                }
                if (s[i] != s[j]) {
                    dp[i][j] = 0;
                } else {
                    if (l <= 2) { // 子串长为2
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if (dp[i][j] == 1 && l > maxlen) {
                    maxlen = l;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxlen);
    }
};