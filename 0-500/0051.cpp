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
