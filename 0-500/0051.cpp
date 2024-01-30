class Solution {
public:
    int a[10] = {0};
    vector<vector<string>> result;
    bool check(int row,int col)
    {
        if (row == 1) return true;
        for (int i = 1; i < row; ++i)
        {
            if ((abs(a[row] - a[i]) == abs(row - i)) || (a[i] == col))
                return false;
        }
        return true;
    }

    void backtrack(int row, int n)
    {
        if (row > n)
        {
            string init;
            for(int i=0;i<n;++i) init+='.';
            vector<string> tmp;
            string s;
            for(int i=1;i<=n;++i){
                init[a[i]-1] = 'Q';
                s = init;
                tmp.push_back(s);
                init[a[i]-1] = '.';
            }
            result.push_back(tmp);
        }
        else
        {
            for (int i = 1; i <= n; ++i)
            {
                a[row] = i;
                if (check(row,i))
                {
                    backtrack(row + 1, n);
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        backtrack(1,n);

        return result;
    }
};

// finished in 2024.1.30
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if (n == 0) {
            return ans;
        }
        vector<string> board(n, string(n, '.'));
        vector<bool> column(n, false), ldiag(2*n-1, false), rdiag(2*n-1, false);
        backtracking(ans, board, column, ldiag, rdiag, 0, n);
        return ans;
    }
// 辅函数
    void backtracking(vector<vector<string>> &ans, vector<string> &board, vector<bool> &column, 
                        vector<bool> &ldiag, vector<bool> &rdiag, int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (column[i] || ldiag[n-row+i-1] || rdiag[row+i]) {
                continue;
            }
            // 修改当前节点状态
            board[row][i] = 'Q';
            column[i] = ldiag[n-row+i-1] = rdiag[row+i] = true;
            // 递归子节点
            backtracking(ans, board, column, ldiag, rdiag, row+1, n);
            // 回改当前节点状态
            board[row][i] = '.';
            column[i] = ldiag[n-row+i-1] = rdiag[row+i] = false;
        }
    }
};