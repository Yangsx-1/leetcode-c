class Solution {
public:
    int jump(vector<int>& nums) {
        int l = nums.size();
        vector<int> dp(l,l);
        dp[0] = 0;
        for(int i=0; i<l; ++i){
            for(int j=1; j<=nums[i] && i+j<l; ++j){
                dp[i+j] = min(dp[i]+1,dp[i+j]);
            }
        }
        return dp[l-1];
    }
};

// finished in 2024.2.20
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxpos = 0, n = nums.size(), step = 0, end = 0;
        for (int i = 0; i < n-1; ++i) {
            maxpos = max(maxpos, i+nums[i]);
            if (i == end) {
                end = maxpos;
                ++step;
            }
        }
        return step;
    }
};