// finished in 2024.1.8
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        vector<int> ans = {-1, -1};
        if (l < nums.size() && nums[l] == target) {
            ans[0] = l;
            while (l < nums.size() && nums[l] == target) l++;
            ans[1] = l - 1;
        }
        return ans;
    }
};