// finished in 2024.2.15
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> stot;
        unordered_map<char, char> ttos;
        for (int i = 0; i < s.size(); ++i) {
            char x = s[i], y = t[i];
            if ((stot.count(x) && stot[x] != y) || (ttos.count(y) && ttos[y] != x)) {
                return false;
            }
            stot[x] = y;
            ttos[y] = x;
        }
        return true;
    }
};