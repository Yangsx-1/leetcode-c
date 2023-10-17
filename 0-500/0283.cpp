class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        int size = nums.size();
        while (right < size) {
            if (nums[right] != 0) {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
                left++;
                right++;
            } else {
                right++;
            }
        }
    }
};