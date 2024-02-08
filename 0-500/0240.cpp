// finished in 2024.2.8
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n-1;
        while(x < m && y >= 0) {
            int curr = matrix[x][y];
            if (curr == target) {
                return true;
            } else if (curr < target) {
                ++x;
            } else {
                --y;
            }
        }
        return false;
    }
};