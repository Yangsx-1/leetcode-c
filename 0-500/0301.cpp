// finished in 2024.1.17
class Solution {
public:
    inline bool isValid(const string & str) {
        int cnt = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                cnt++;
            } else if (str[i] == ')') {
                cnt--;
                if (cnt < 0) {
                    return false;
                }
            }
        }
        return cnt == 0;
    }

    vector<string> res;

    void helper(string str, int index, int lremove, int rremove) {
        if (lremove == 0 && rremove == 0) {
            if (isValid(str)) {
                res.push_back(str);
            }
            return;
        }

        for (int i = index; i < str.size(); ++i) {
            if (i != index && str[i] == str[i-1]) {
                continue;
            }
            if (lremove + rremove > str.size() - i) {
                return;
            }
            if (lremove > 0 && str[i] == '(') {
                helper(str.substr(0, i) + str.substr(i+1), i, lremove-1, rremove);
            }
            if (rremove > 0 && str[i] == ')') {
                helper(str.substr(0, i) + str.substr(i+1), i, lremove, rremove-1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int lremove = 0;
        int rremove = 0;

        for (char c : s) {
            if (c == '(') {
                lremove++;
            } else if (c == ')') {
                if (lremove == 0) {
                    rremove++;
                } else {
                    lremove--;
                }
            }
        }
        helper(s, 0, lremove, rremove);
        return res;
    }
};