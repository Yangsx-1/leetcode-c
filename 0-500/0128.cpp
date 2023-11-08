class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        set<int> s;
        for(auto x : nums) {
            s.insert(x);
        }
        int max_count = 1;
        auto it=s.begin();
        int last = *it;
        it++;
        int count = 1;
        for(; it != s.end(); ++it) {
            if(*it != last+1) {
                count = 1;
            } else {
                count++;
            }
            last = *it;
            if(count > max_count) max_count = count;
        }
        return max_count;
    }
};