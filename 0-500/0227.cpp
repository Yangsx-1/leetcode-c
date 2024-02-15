// finished in 2024.2.15
class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char presign = '+';
        int num = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + int(s[i]-'0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n-1) {
                switch (presign) {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    case '/':
                        stk.back() /= num;
                        break;
                }
                presign = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};