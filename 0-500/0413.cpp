// finished in 2024.2.1
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        vector<int> record(n);
        int last_diff = nums[1] - nums[0];
        for (int i = 2; i < n; ++i) {
            int diff = nums[i] - nums[i-1];
            if (diff == last_diff) {
                record[i] = record[i-1] + 1;
            }
            last_diff = diff;
        }
        int count = 0;
        for (const auto& it : record) {
            count += it;
        }
        return count;
    }
};