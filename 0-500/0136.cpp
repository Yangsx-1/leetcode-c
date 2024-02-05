class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> umap;
        int l =nums.size();
        for(int i=0; i < l; ++i){
            if(umap.find(nums[i]) == umap.end()) umap.emplace(nums[i],1);
            else umap[nums[i]] = 2;
        }
        int r = 0;
        for(int i=0;i<l;++i){
            if(umap[nums[i]] == 1){
                r = nums[i];
                break;
            }
        }
        return r;
    }
};

// finished in 2024.2.5
// 异或非常巧妙
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (const auto& it : nums) {
            ans ^= it;
        }
        return ans;
    }
};