// finished in 2024.2.18
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int index = 0;
        while (index < nums.size()) {
            int tmp = index;
            string s = to_string(nums[index]);
            while (index+1 < nums.size() && nums[index]+1 == nums[index+1]) {
                ++index;
            }
            if (index == tmp) {
                ans.emplace_back(s);
            } else {
                s = s + "->" + to_string(nums[index]);
                ans.emplace_back(s);
            }
            ++index;
        }
        return ans;
    }
};