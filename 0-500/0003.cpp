// finished in 2023.11.1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_set<int> us;
        int count = 0, max_count = 0;
        for (int i = 0; i < s.size(); ++i) {
            count++;
            while (us.find(s[i]) != us.end()) {
                us.erase(s[left]);
                count--;
                left++;
            }
            if (count > max_count) max_count = count;
            us.insert(s[i]);
        }
        return max_count;
    }
};