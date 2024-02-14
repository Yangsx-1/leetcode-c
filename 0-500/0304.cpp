// finished in 2024.2.14
class NumMatrix {
private:
    vector<vector<int>> prematrix;
public:
    NumMatrix(vector<vector<int>>& matrix) : prematrix(matrix.size()+1, vector<int>(matrix[0].size()+1)) {
        for (int i = 1; i < prematrix.size(); ++i) {
            for (int j = 1; j < prematrix[0].size(); ++j) {
                prematrix[i][j] = matrix[i-1][j-1] + prematrix[i-1][j] + prematrix[i][j-1] - prematrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prematrix[row2+1][col2+1]-prematrix[row1][col2+1]-prematrix[row2+1][col1]+prematrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */