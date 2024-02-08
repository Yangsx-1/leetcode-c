// finished in 2024.2.8
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if (num1.size() <= num2.size()) {
            int m = num2.size() - num1.size();
            for (int i = 0; i < m; ++i) {
                num1 += '0';
            }
        } else {
            int m = num1.size() - num2.size();
            for (int i = 0; i < m; ++i) {
                num2 += '0';
            }
        }
        int adv = 0;
        for (int i = 0; i < num1.size(); ++i) {
            int tmp = (num1[i] - '0') + (num2[i] - '0') + adv;
            num1[i] = char(tmp % 10 + '0');
            if (tmp >= 10) adv = 1;
            else adv = 0;
        }
        if (adv > 0) {
            num1 += '1';
        }
        reverse(num1.begin(), num1.end());
        return num1;
    }
};