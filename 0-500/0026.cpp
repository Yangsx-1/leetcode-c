class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int cmp = nums[0];
        for (auto iter = nums.begin() + 1; iter != nums.end();) {
            if (*iter == cmp) nums.erase(iter);
            else {
                cmp = *iter;
                count++;
                iter++;
            }
        }
        return count;
    }
};