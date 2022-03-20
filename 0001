class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = nums.size();
        int t1=0,t2=0;
        bool flag = false;
        for(int i=0;i<l; ++i){
            for(int j=i+1;j<l;++j){
                if(nums[i]+nums[j] == target){
                    t1 = i;
                    t2 = j;
                    flag = true;
                    if(flag) break;
                }
            }
            if(flag) break;
        }
        vector<int> out = {t1,t2};
        return out;
    }
};
