// finished in 2024.2.13
class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> index;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (index.find(val) == index.end()) {
            nums.emplace_back(val);
            index[val] = nums.size()-1;
            return true;
        } else {
            return false;
        }
    }
    
    bool remove(int val) {
        if (index.find(val) == index.end()) {
            return false;
        } else {
            int id = index[val];
            int last = nums.back();
            nums[id] = last;
            index[last] = id;
            nums.pop_back();
            index.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */