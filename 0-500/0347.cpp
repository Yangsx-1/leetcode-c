// finished in 2024.1.21
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for (int i : nums) {
            umap[i] += 1;
        }
        vector<pair<int,int>> min_heap(k);
        for (const auto &it : umap) {
            if (it.second > min_heap[0].second) {
                min_heap[0] = it;
                for (int i = 0; i < k; ){
                    if (i * 2 >= k) break;
                    int l = i * 2 + 1, r = i * 2 + 2;
                    int smallest = i;
                    if (l < k && min_heap[l].second < min_heap[smallest].second) {
                        smallest = l;
                    }
                    if (r < k && min_heap[r].second < min_heap[smallest].second) {
                        smallest = r;
                    }
                    if (smallest != i) {
                        swap(min_heap[smallest], min_heap[i]);
                        i = smallest;
                    } else {
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        for (const auto &it : min_heap) {
            ans.emplace_back(it.first);
        }
        return ans;
    }
};