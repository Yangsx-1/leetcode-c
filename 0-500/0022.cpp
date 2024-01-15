// finished in 2024.1.15
class Solution {
public:
    vector<string> ans;
    void tracing(int n, int left, int right, string s) {
        if (left < n) {
            if (right < left) {
                tracing(n, left + 1, right, s + '(');
                tracing(n, left, right + 1, s + ')');
            } else {
                tracing(n, left + 1, right, s + '(');
            }
        } else {
            while (right < left) {
                s += ')';
                right++;
            }
            ans.push_back(s);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        tracing(n, 0, 0, "");
        return ans;
    }
};