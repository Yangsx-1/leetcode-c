class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = nums[0];
        int big = m;
        int l = nums.size();
        if(l==1) return m;
        for(int i=1; i<l; ++i){
            m = max(m+nums[i],nums[i]);
            if(big < m) big = m;
        }
        return big;
    }
};

// finished in 2024.1.18
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxans = nums[0];
        for (const auto &x : nums) {
            pre = max(pre + x, x);
            maxans = max(maxans, pre);
        }
        return maxans;
    }
};