// finished in 2024.2.14
class NumArray {
private:
    vector<int> prefixsum;
public:
    NumArray(vector<int>& nums) {
        int s = 0;
        prefixsum.emplace_back(s);
        for (auto& num : nums) {
            s += num;
            prefixsum.emplace_back(s);
        }
    }
    
    int sumRange(int left, int right) {
        return prefixsum[right+1]-prefixsum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */