class Solution {
public:
    int rob(vector<int>& nums) {
        int l = nums.size();
        if(l == 1) return nums[0];
        int tmp = nums[0]>nums[1]?nums[0]:nums[1];
        if(l == 2) return tmp;
        vector<int> dp = {nums[0]};
        dp.push_back(tmp);
        for(int i=2; i<l; ++i){
            tmp = dp[i-1]>(dp[i-2]+nums[i])?dp[i-1]:(dp[i-2]+nums[i]);
            dp.push_back(tmp);
        }
        return dp[l-1];
    }
};
