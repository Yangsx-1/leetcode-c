class Solution {
public:
    int dp[2501];
    int lengthOfLIS(vector<int>& nums) {
        for(int i=0;i<2501;++i) dp[i] = 1;
        int l = nums.size();
        for(int i=0;i<l;++i){
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        int max=-1;
        for(int i=0;i<l;++i){
            if(max<dp[i]) max=dp[i];
        }
        return max;
    }
};
