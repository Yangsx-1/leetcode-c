// finished in 2024.2.7
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string ans = "";
        int n = num < 0 ? -num : num;
        while (n > 0) {
            ans += to_string(n % 7);
            n /= 7;
        }
        if (num < 0) ans += '-';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};