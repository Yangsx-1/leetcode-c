// finished in 2024.1.18
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        int landnum = 0;
        for (int x = 0; x < grid.size(); ++x) {
            for (int y = 0; y < grid[0].size(); ++y) {
                if (grid[x][y] == '1') {
                    landnum++;
                    q.push({x, y});
                    grid[x][y] = '0';
                    while(!q.empty()) {
                        auto tmp = q.front();
                        q.pop();
                        int row = tmp.first, col = tmp.second;
                        if (row > 0 && grid[row-1][col] == '1') {
                            grid[row-1][col] = '0';
                            q.push({row-1, col});
                        }
                        if (row < grid.size() - 1 && grid[row+1][col] == '1') {
                            grid[row+1][col] = '0';
                            q.push({row+1, col});
                        }
                        if (col > 0 && grid[row][col-1] == '1') {
                            grid[row][col-1] = '0';
                            q.push({row, col-1});
                        }
                        if (col < grid[0].size() - 1 && grid[row][col+1] == '1') {
                            grid[row][col+1] = '0';
                            q.push({row, col+1});
                        }
                    }
                }
            }
        }
        return landnum;
    }
};