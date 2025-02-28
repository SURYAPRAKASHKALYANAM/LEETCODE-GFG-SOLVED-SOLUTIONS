class Solution {
public:
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
    bool dfs(int r, int c, int pos, int n, int m, int len,
             vector<vector<char>>& board, string word) {
        if (pos>=len) return true;
        char ch=board[r][c];
        board[r][c]='#';
        for (int i = 0; i < 4; i++) {
            int row = r + dx[i], col = c + dy[i];
            if (row >= 0 && row < m && col >= 0 && col < n &&
                word[pos]==board[row][col]) {
                if (dfs(row, col, pos + 1, n, m, len, board, word))
                    return true;
            }
        }
        board[r][c]=ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.size();
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 1, n, m, len, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};