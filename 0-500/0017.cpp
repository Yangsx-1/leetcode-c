// finished in 2024.1.15
class Solution {
public:
    vector<string> button = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void tracing(int index, string s, vector<string> &v, string &digits) {
        if (index == digits.size()) {
            v.push_back(s);
            return;
        } else {
            for (auto tmp : button[digits[index]-'0']) {
                tracing(index + 1, s + tmp, v, digits);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;
        tracing(0, "", ans, digits);
        return ans;
    }
};