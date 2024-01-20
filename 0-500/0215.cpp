// finished in 2024.1.20
class Solution {
public:
    int quickselect(vector<int> &nums, int l, int r, int k) {
        if (l == r) {
            return nums[k];
        }
        int pivot = nums[l], i = l, j = r;
        while (i < j) {
            while (i < j && nums[j] > pivot) {
                --j;
            }
            if (i < j) {
                swap(nums[i++], nums[j]);
            }
            // 这里不管与pivot相等的元素很重要，正常情况下需要管一下比较好
            // 在leetcode中测试得出，只有一个等号是最快的
            while (i < j && nums[i] < pivot) { 
                ++i;
            }
            if (i < j) {
                swap(nums[i], nums[j--]);
            }
        }
        if (k == j) {
            return nums[k];
        } else if (k < j) {
            return quickselect(nums, l, j-1, k);
        }
        return quickselect(nums, j+1, r, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, 0, nums.size()-1, nums.size()-k);
    }
};