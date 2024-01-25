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

// finished in 2024.1.25
class Solution { // 自己想的，比较好理解
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> ifsteal(n);
        vector<int> notsteal(n);
        ifsteal[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            ifsteal[i] = max(notsteal[i-1], ifsteal[i-1] - nums[i-1]) + nums[i];
            notsteal[i] = max(ifsteal[i-1], notsteal[i-1]);
        }
        return max(ifsteal[n-1], notsteal[n-1]);
    }
};

// 官方题解
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        vector<int> dp = vector<int>(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[size - 1];
    }
};