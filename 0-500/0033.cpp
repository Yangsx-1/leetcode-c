// finished in 2024.1.8
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int n = nums.size();
        if (n == 1) return nums[0] == target ? 0 : -1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[left] < nums[right]) {
                if (nums[mid] > target) {
                    right = mid - 1;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] > nums[right]) { // right is not-sorted
                    if (nums[mid] > target && nums[left] <= target) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                } else { // left is not-sorted
                    if (nums[mid] < target && nums[right] >= target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }
        if (nums[left] == target) return left;
        return -1;
    }
};