class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = 0;
        for (int val : nums) {
            maxVal = max(maxVal, val);
        }
        vector<int> sum(maxVal + 1);
        for (int val : nums) {
            sum[val] += val;
        }
        vector<int> dp(maxVal + 1);
        dp[0] = sum[0];
        dp[1] = max(sum[0],sum[1]);
        for(int i=2; i<maxVal+1; ++i){
            dp[i] = max(dp[i-1],dp[i-2]+sum[i]);
        }
        return dp[maxVal];
    }
};
