// finished in 2024.1.28
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while (l < r) {
            int sumtwo = numbers[l] + numbers[r];
            if (sumtwo == target) {
                return {l+1, r+1};
            } else {
                if (sumtwo > target) {
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return {0, 0};
    }
};