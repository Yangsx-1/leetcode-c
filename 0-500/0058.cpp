// finished in 2024.2.18
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            } else {
                if (count != 0 && i >= 1 && s[i-1] == ' ') count = 0;
                ++count;
            }
        }
        return count;
    }
};