// finished in 2024.2.6
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        int l = 0, r = nums.size()-1;
        while (l < r) {
            if (nums[l] != val) {
                ++l;
            } else {
                while (l < r && nums[r] == val) {
                    --r;
                }
                swap(nums[l], nums[r]);
                --r;
            }
        }
        if (nums[l] == val) --l;
        return l+1;
    }
};