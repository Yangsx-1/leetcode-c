// finished in 2024.2.9
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minsize = INT_MAX;
        for (const auto& s : strs) {
            if (s.size() < minsize) minsize = s.size();
        }
        string ans;
        for (int i = 0; i < minsize; ++i) {
            bool isallsame = true;
            char ch = strs[0][i];
            for (const auto& s : strs) {
                if (s[i] != ch) isallsame = false;
            }
            if (!isallsame) break;
            ans += ch;
        }
        return ans;
    }
};