// finished in 2024.1.16
class Solution {
public:
    bool tracing(vector<vector<char>>& board, string &word, int index, int x, int y) {
        if(index == word.size()) return true;
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '\0' || board[x][y] != word[index])
            return false;
        char tmp = board[x][y];
        board[x][y] = '\0';
        if(tracing(board, word, index + 1, x + 1, y) || 
           tracing(board, word, index + 1, x - 1, y) ||
           tracing(board, word, index + 1, x, y + 1) ||
           tracing(board, word, index + 1, x, y - 1))
            return true;
        board[x][y] = tmp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m, n;
        for(m = 0; m < board.size(); ++m){
            for(n = 0; n < board[0].size(); ++n){
                if(board[m][n] == word[0]) {
                    bool ans = tracing(board, word, 0, m, n);
                    if (ans) return true;
                }
            }
        }
        return false;
    }
};