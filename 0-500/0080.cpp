// finished in 2024.2.6
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        int fast = 2, slow = 2;
        while (fast < n) {
            if (nums[fast] != nums[fast-1]) {
                nums[slow] = nums[fast];
                ++slow;
            } else if (nums[slow-2] != nums[slow-1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};