// finished in 2024.2.7
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        q.splice(q.begin(), q, mp[key]);
        return q.front().second;
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            if (q.size() == cap) {
                mp.erase(q.back().first);
                q.pop_back();
            }
            q.push_front({key, value});
            mp[key] = q.begin();
        } else {
            q.splice(q.begin(), q, mp[key]);
            q.front().second = value;
        }
    }
private:
    list<pair<int, int>> q;
    int cap;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */