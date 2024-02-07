// finished in 2024.2.7
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> rear(n);
        int product = 1;
        for (int i = 0; i < n; ++i) {
            pre[i] = product * nums[i];
            product = pre[i];
        }
        product = 1;
        for (int i = n-1; i >= 0; --i) {
            rear[i] = product * nums[i];
            product = rear[i];
        }
        vector<int> ans(n);
        ans[0] = rear[1];
        for (int i = 1; i < n-1; ++i) {
            ans[i] = pre[i-1] * rear[i+1];
        }
        ans[n-1] = pre[n-2];
        return ans;
    }
};

// two pointer
//维护两个变量，beforeSum表示前缀和，afterSum表示后缀和
public int[] productExceptSelf(int[] nums) {
    int n=nums.length;
    int[] ans=new int[n];
    Arrays.fill(ans,1);
    int beforeSum=1;
    int afterSum=1;
    for(int i=0,j=n-1;i<n;i++,j--){
        ans[i]*=beforeSum;
        ans[j]*=afterSum;
        beforeSum*=nums[i];
        afterSum*=nums[j];
    }
    return ans;
}