// finished in 2024.1.30
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void dfs(int n, int k, int i) {
        if (cur.size() == k) {
            ans.push_back(cur);
            return;
        }
        if (n - i + 1 < k - cur.size()) {
            return;
        }
        for (int m = i; m <= n; ++m) {
            cur.push_back(m);
            dfs(n, k, m+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }
};