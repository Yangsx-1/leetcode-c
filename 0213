class Solution {
public:
    int robtest(vector<int> nums, bool judge=true) {
        int l = nums.size();
        if(l == 1) return nums[0];
        int tmp = nums[0]>nums[1]?nums[0]:nums[1];
        if(l == 2) return tmp;
        if(judge == false) nums.pop_back();
        else nums.erase(nums.begin());
        l = nums.size();
        vector<int> dp = {nums[0]};
        tmp = nums[0]>nums[1]?nums[0]:nums[1];
        dp.push_back(tmp);
        for(int i=2; i<l; ++i){
            tmp = dp[i-1]>(dp[i-2]+nums[i])?dp[i-1]:(dp[i-2]+nums[i]);
            dp.push_back(tmp);
        }
        return dp[l-1];
    }
    int rob(vector<int>& nums) {
        int rob1 = robtest(nums);
        int rob2 = robtest(nums, false);
        int cmp = rob1>rob2?rob1:rob2;
        return cmp;
    }
};
