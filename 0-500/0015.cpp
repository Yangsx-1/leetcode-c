class Solution {
public:
    static bool cmp(int x,int y){
        return x<y;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return {};
        sort(nums.begin(),nums.end(),cmp);
        vector<vector<int>> out;
        int i=0; 
        while(i<nums.size()-2){
            int l=i+1,r=nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r] < (-nums[i])){
                    while(l<nums.size()-2 && nums[l] == nums[l+1]) l++;
                    l++;
                }
                else if(nums[l]+nums[r] > (-nums[i])){
                    while(r>i+1 && nums[r] == nums[r-1]) r--;
                    r--;
                }
                else{
                    out.push_back({nums[i],nums[l],nums[r]});
                    while(l<nums.size()-2 && nums[l] == nums[l+1]) l++;
                    while(r>i+1 && nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }
            }
            while(i<nums.size()-2 && nums[i] == nums[i+1]) i++;
            i++;
            if(nums[i]>0) break;
        }
        return out;
    }
};
