// finished in 2024.1.16
class Solution {
public:
    void tracing(vector<int> &s, vector<vector<int>> &ans, int index, const vector<int> &nums) {
        ans.push_back(s);
        for (int i = index; i < nums.size(); ++i) {
            s.push_back(nums[i]);
            tracing(s, ans, i + 1, nums);
            s.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> s;
        tracing(s, ans, 0, nums);
        return ans;
    }
};