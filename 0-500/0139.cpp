// finished in 2024.1.24
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (const auto& it : wordDict) {
            dict.insert(it);
        }
        vector<int> dp(s.size()+1);
        dp[0] = 1;
        for (int i = 1; i < s.size()+1; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.find(s.substr(j, i-j))!=dict.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};