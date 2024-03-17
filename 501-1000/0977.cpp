// finished in 2024.3.11
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l = 0, r = nums.size()-1, id = nums.size()-1;
        while(id >= 0) {
            if (pow(nums[l],2) > pow(nums[r],2)) {
                ans[id--] = pow(nums[l++],2);
            } else {
                ans[id--] = pow(nums[r--],2);
            }
        }
        return ans;
    }
};