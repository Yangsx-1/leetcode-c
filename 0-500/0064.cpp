// finished in 2024.1.22
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> matrix(grid[0].size());
        matrix[0] = grid[0][0];
        for (int x = 0; x < grid.size(); ++x) {
            for (int y = 0; y < grid[0].size(); ++y) {
                if (x == 0) {
                    if (y != 0) {
                        matrix[y] = matrix[y-1] + grid[x][y];
                    }
                }
                else if (y == 0) {
                    if (x != 0) {
                        matrix[y] = matrix[y] + grid[x][y];
                    }
                }
                else {
                    matrix[y] = min(matrix[y-1], matrix[y]) + grid[x][y];
                }
            }
        }
        return matrix[grid[0].size()-1];
    }
};