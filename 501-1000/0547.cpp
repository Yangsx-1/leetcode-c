// finished in 2024,1,30
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i) {
        isConnected[i][i] = 0;
        for (int x = 0; x < isConnected[0].size(); ++x) {
            if (isConnected[i][x] != 0) {
                isConnected[i][x] = 0;
                isConnected[x][i] = 0;
                dfs(isConnected, x);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        for (int x = 0; x < isConnected.size(); ++x) {
            if (isConnected[x][x] != 0) {
                count += 1;
                dfs(isConnected, x);
            }
        }
        return count;
    }
};