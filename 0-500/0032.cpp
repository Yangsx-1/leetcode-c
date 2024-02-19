// finished in 2024.2.19
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxlen = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++left;
            } else {
                ++right;
            }
            if (left == right) {
                maxlen = max(maxlen, left+right);
            } else if (right > left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.size()-1; i >= 0; --i) {
            if (s[i] == '(') {
                ++left;
            } else {
                ++right;
            }
            if (left == right) {
                maxlen = max(maxlen, left+right);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return maxlen;
    }
};