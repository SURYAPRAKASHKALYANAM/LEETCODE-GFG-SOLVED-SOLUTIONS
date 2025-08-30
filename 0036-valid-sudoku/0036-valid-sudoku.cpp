class Solution {
public:
    bool isNotValid(int r, int c, char ch, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if ((i != c && board[r][i] == ch) || (i != r && board[i][c] == ch))
                return true;
            int row = 3 * (r / 3) + (i / 3), col = 3 * (c / 3) + i % 3;
            if ((board[row][col] == ch && (row != r && col != c)))
                return true;
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' &&
                    isNotValid(i, j, board[i][j], board)) {
                    return false;
                }
            }
        }
        return true;
    }
};