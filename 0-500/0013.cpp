// finished in 2024.2.9
class Solution {
    private:
    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.size()-1; ++i) {
            if (symbolValues[s[i]] < symbolValues[s[i+1]]) {
                ans -= symbolValues[s[i]];
            } else {
                ans += symbolValues[s[i]];
            }
        }
        ans += symbolValues[s[s.size()-1]];
        return ans;
    }
};