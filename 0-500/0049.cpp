// finished in 2023.11.7
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for (auto it : strs) {
            string key = it;
            sort(key.begin(), key.end());
            umap[key].emplace_back(it);
        }
        vector<vector<string>> ans;
        for(auto it : umap) {
            ans.emplace_back(it.second);
        }
        return ans;
    }
};