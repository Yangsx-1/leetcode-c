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

// finished in 2024.2.5
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == num) {
                ++count;
            } else {
                --count;
                if (count < 0) {
                    num = nums[i];
                    count = 1;
                }
            }
        }
        return num;
    }
};