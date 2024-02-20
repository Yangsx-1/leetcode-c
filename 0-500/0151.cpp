// finished in 2024.2.20
class Solution {
public:
    string reverseWords(string s) {
        // 使用双指针
        int m = s.size() - 1;
        string res;
        // 除去尾部空格
        while (s[m] == ' ' && m > 0) m--;
        int n = m; // n是另一个指针
        while (m >= 0) {
            while (m >= 0 && s[m] != ' ') m--;
            res += s.substr(m + 1, n - m) + " "; // 获取单词并加上空格
            while (m >= 0 && s[m] == ' ') m--;
            n = m;
        }
        return res.substr(0, res.size() - 1); // 忽略最后一位的空格
    }
};