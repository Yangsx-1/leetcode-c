class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0,white=0;
        int l = nums.size();
        for(int i=0; i<l; ++i){
            if(nums[i] == 0){
                swap(nums[red],nums[i]);
                if(red<white) swap(nums[white],nums[i]);
                red++;
                white++;
            }
            else if(nums[i] == 1){
                swap(nums[white], nums[i]);
                white++;
            }
        }
    }
};
