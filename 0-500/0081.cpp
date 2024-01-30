// finished in 2024.1.29
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] == nums[l]) { // 无法判断哪边有序，如[1,1,1,1,1,1,1,1,2,1,1,1,1]
                ++l;
            } else if (nums[mid] == nums[r]) {
                --r;
            } else if (nums[mid] < nums[r]) { // 右侧有序
                if (nums[mid] <= target && nums[r] >= target) {
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            } else { // 左侧有序
                if (nums[mid] >= target && nums[l] <= target) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
        }
        return false;
    }
};