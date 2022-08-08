class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m = 0;
        int count = 0;
        int l =nums.size();
        for(int i=0;i<l;++i){
            if(count == 0){
                m = nums[i];
            }
            if(m == nums[i]) count++;
            else count--;
        }
        return m;
    }
};
