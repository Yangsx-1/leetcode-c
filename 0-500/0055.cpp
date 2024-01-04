class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l =nums.size();
        vector<bool> check(l);
        check[0] = true;
        for(int i = 0; i < l; ++i){
            if(check[i] == false) continue;
            for(int j = 1; j <= nums[i] && i+j < l; ++j){
                check[i+j] = true;
            }
        }
        return check[l-1];
    }
};
//以上为第一版解答，但超时

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = nums.size();
        int m = 0;
        for(int i = 0; i < l; ++i){
            if(m<i) return false;
            m = max(m,i+nums[i]);
        }
        return true;
    }
};

// finished in 2024.1.4
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxpos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxpos) return false;
            int pos = i + nums[i];
            if (pos > maxpos) maxpos = pos;
        }
        return true;
    }
};