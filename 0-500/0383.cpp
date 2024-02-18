// finished in 2024.2.18
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for (char it : magazine) {
            mp[it] += 1;
        }
        for (char it : ransomNote) {
            if (mp.find(it) == mp.end() || mp[it] == 0) {
                return false;
            } else {
                mp[it] -= 1;
            }
        }
        return true;
    }
};