// finished in 2024.1.22
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m, vector<int>(n));
        matrix[0][0] = 1;
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (x == 0) {
                    if (y != 0) {
                        matrix[x][y] = matrix[x][y-1];
                    }
                }
                else if (y == 0) {
                    if (x != 0) {
                        matrix[x][y] = matrix[x-1][y];
                    }
                }
                else {
                    matrix[x][y] = matrix[x][y-1] + matrix[x-1][y];
                }
            }
        }
        return matrix[m-1][n-1];
    }
};