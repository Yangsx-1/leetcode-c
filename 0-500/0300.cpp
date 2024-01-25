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

// finished in 2024.1.25
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        int maxans = 1;
        dp[0] = 1;
        for(int i = 1; i < nums.size(); ++i) {
            int lastmax = 0;
            for (int j = i; j >= 0; --j) {
                if (nums[i] > nums[j]) {
                    if (dp[j] > lastmax) lastmax = dp[j];
                }
            }
            dp[i] = lastmax + 1;
            if (dp[i] > maxans) maxans = dp[i];
        }
        return maxans;
    }
};