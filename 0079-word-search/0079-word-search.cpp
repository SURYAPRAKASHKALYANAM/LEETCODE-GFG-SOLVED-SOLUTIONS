class Solution {
public:
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
    bool dfs(int r, int c, int pos, int n, int m, int len,
             vector<vector<char>>& board, string word,
             vector<vector<int>> visited) {
        if (pos+1> len)
            return false;
        if (word[pos] != board[r][c])
            return false;
        if(pos==len-1)  return true;
        visited[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            int row = r + dx[i], col = c + dy[i];
            if (row >= 0 && row < m && col >= 0 && col < n &&
                !visited[row][col] && word[pos+1]==board[row][col]) {
                if (dfs(row, col, pos + 1, n, m, len, board, word, visited))
                    return true;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.size();
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> visited(m, vector<int>(n, 0));
                    if (dfs(i, j, 0, n, m, len, board, word, visited))
                        return true;
                }
            }
        }
        return false;
    }
};