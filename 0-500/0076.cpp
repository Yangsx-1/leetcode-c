class Solution {
public:
    unordered_map<char, int> s_map, t_map;//必须要用全局变量，不然会导致额外的拷贝，影响性能

    bool check_ok (){
        for (auto it : t_map) {
            if (s_map[it.first] < it.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (int i = 0; i < t.size(); ++i) {
            t_map[t[i]] += 1;
        }
        int first = 0, last = 0;
        int ans = -1, len = INT_MAX;
        int size = s.size();
        while (last < size) {
            if (t_map.find(s[last]) != t_map.end()) {
                s_map[s[last]] += 1;
            }
            while (check_ok() && first <= last) {
                if (last - first + 1 < len) {
                    ans = first;
                    len = last - first + 1;
                }
                if (s_map.find(s[first]) != s_map.end()) {
                    s_map[s[first]]--;
                }
                first++;
            }
            last++;
        }
        return ans == -1 ? "" : s.substr(ans, len);
    }
};