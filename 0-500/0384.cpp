// finished in 2024.2.10
class Solution {
    vector<int> origin;
public:
    Solution(vector<int>& nums) {
        origin = move(nums);
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled(origin);
        for (int i = 0; i < shuffled.size(); ++i) {
            int j = i + rand() % (shuffled.size()-i);
            swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */