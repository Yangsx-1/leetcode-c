// finished in 2024.2.7
class LFUCache {
public:
    struct node {
        int key, val, freq;
        node(int k, int v, int f) : key(k), val(v), freq(f) {}
    };
    LFUCache(int capacity) {
        minfreq = 0;
        cap = capacity;
    }
    
    int get(int key) {
        if (key_table.find(key) == key_table.end()) return -1;
        auto& it = key_table[key];
        auto& f = it->freq;
        freq_table[f+1].splice(freq_table[f+1].begin(), freq_table[f], it);
        if (freq_table[f].size() == 0) {
            freq_table.erase(f);
            if (minfreq == f) minfreq += 1;
        }
        f += 1;
        return it->val;
    }
    
    void put(int key, int value) {
        if (key_table.find(key) == key_table.end()) {
            if (key_table.size() == cap) {
                auto it = freq_table[minfreq].back();
                key_table.erase(it.key);
                freq_table[minfreq].pop_back();
                if (freq_table[minfreq].size() == 0) {
                    freq_table.erase(minfreq);
                }
            }
            freq_table[1].push_front(node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        } else {
            auto& it = key_table[key];
            it->val = value;
            auto& f = it->freq;
            freq_table[f+1].splice(freq_table[f+1].begin(), freq_table[f], it);
            if (freq_table[f].size() == 0) {
                freq_table.erase(f);
                if (minfreq == f) minfreq += 1;
            }
            f += 1;
        }
    }
private:
    int minfreq, cap;
    unordered_map<int, list<node>::iterator> key_table;
    unordered_map<int, list<node>> freq_table;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */