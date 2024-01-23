// finished in 2024.1.23
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < i + 2; ++j) {
                if (j >= n) break;
                int l = i, r = j;
                while (l >=0 && r <= n && s[l] == s[r]) {
                    --l;
                    ++r;
                    ++ans;
                }
            }
        }
        return ans;
    }
};