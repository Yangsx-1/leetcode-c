// finished in 2024.1.15
class Solution {
public:
    vector<vector<int>> ans;
    void tracing(int index, int target, vector<int> &candidates, vector<int> &tmp_ans) {
        if (index == candidates.size()) return;
        if (target == 0) {
            ans.push_back(tmp_ans);
            return;
        } else if (target < 0) {
            return;
        } else {
            tracing(index + 1, target, candidates, tmp_ans);
            tmp_ans.push_back(candidates[index]);
            tracing(index, target - candidates[index], candidates, tmp_ans);
            tmp_ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp_ans;
        tracing(0, target, candidates, tmp_ans);
        return ans;
    }
};