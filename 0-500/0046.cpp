// finished in 2024.1.15
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(vector<int>& nums) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != INT_MAX) {
                int temp = nums[i];
                cur.push_back(nums[i]);
                nums[i] = INT_MAX;
                dfs(nums);
                nums[i] = temp;
                cur.pop_back();
            }
        }
    }
};