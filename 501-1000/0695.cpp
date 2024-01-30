// finished in 2024.1.30
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return 0;
        if (grid[x][y] == 0) return 0;
        grid[x][y] = 0;
        return 1 + dfs(grid, x-1, y) + dfs(grid, x+1, y) + dfs(grid, x, y-1) + dfs(grid, x, y+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int x = 0; x < grid.size(); ++x) {
            for(int y = 0; y < grid[0].size(); ++y) {
                if (grid[x][y] != 0) {
                    int area = dfs(grid, x, y);
                    max_area = max(area, max_area);
                }
            }
        }
        return max_area;
    }
};