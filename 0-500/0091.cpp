// finished in 2024.2.1
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        vector<int> dp(s.size());
        dp[0] = 1;
        if (s.size() == 1) return 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i-1] == '0') {
                if (s[i] == '0') return 0;
                dp[i] = dp[i-1];
            } else if (s[i] == '0') {
                if (s[i-1] == '0' || s[i-1] > '2') return 0;
                dp[i] = dp[i-1];
            } else if (i+1 < s.size() && s[i+1] == '0') {
                dp[i] = dp[i-1];
            } else if (stoi(s.substr(i-1, 2)) <= 0 || stoi(s.substr(i-1, 2)) > 26) {
                dp[i] = dp[i-1];
            } else {
                if (i >= 2) dp[i] = dp[i-1] + dp[i-2];
                else dp[i] = dp[i-1]+1;
            }
        }
        return dp[s.size()-1];
    }
};

// 优化后的版本
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        dp[0] = 1; // 这里可以用三个变量代替 a=0,b=1,c=0 --> a=b,b=c,c=0
        for (int i = 1; i <= n; ++i) {
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }
            if (i >= 2 && s[i-2] != '0' && (s[i-2]-'0')*10+(s[i-1]-'0') <= 26) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};