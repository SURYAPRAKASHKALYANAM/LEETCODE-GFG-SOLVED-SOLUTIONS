class Solution {
public:
    long long mod = 1e9 + 7;
    int backtrack(int r, int c, int currLen, int n, vector<vector<int>>& dp,
                  vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        if (currLen == n) {
            return dp[r * cols + c][currLen] = 1;
        }
        if (dp[r * cols + c][currLen] != -1)
            return dp[r * cols + c][currLen];
        long long cnt = 0;
        if ((r - 2) >= 0) {
            if (c + 1 < cols && isdigit(board[r - 2][c + 1])) {
                cnt =
                    (cnt + backtrack(r - 2, c + 1, currLen + 1, n, dp, board)) %
                    mod;
            }
            if (c - 1 >= 0 && isdigit(board[r - 2][c - 1])) {
                cnt =
                    (cnt + backtrack(r - 2, c - 1, currLen + 1, n, dp, board)) %
                    mod;
            }
        }
        if (r - 1 >= 0) {
            if (c + 2 < cols && isdigit(board[r - 1][c + 2])) {
                cnt =
                    (cnt + backtrack(r - 1, c + 2, currLen + 1, n, dp, board)) %
                    mod;
            }
            if (c - 2 >= 0 && isdigit(board[r - 1][c - 2])) {
                cnt =
                    (cnt + backtrack(r - 1, c - 2, currLen + 1, n, dp, board)) %
                    mod;
            }
        }
        if (r + 1 < rows) {
            if (c + 2 < cols && isdigit(board[r + 1][c + 2])) {
                cnt =
                    (cnt + backtrack(r + 1, c + 2, currLen + 1, n, dp, board)) %
                    mod;
            }
            if (c - 2 >= 0 && isdigit(board[r + 1][c - 2])) {
                cnt =
                    (cnt + backtrack(r + 1, c - 2, currLen + 1, n, dp, board)) %
                    mod;
            }
        }

        if (r + 2 < rows) {
            if (c + 1 < cols && isdigit(board[r + 2][c + 1])) {
                cnt =
                    (cnt + backtrack(r + 2, c + 1, currLen + 1, n, dp, board)) %
                    mod;
            }
            if (c - 1 >= 0 && isdigit(board[r + 2][c - 1])) {
                cnt =
                    (cnt + backtrack(r + 2, c - 1, currLen + 1, n, dp, board)) %
                    mod;
            }
        }
        return dp[r * cols + c][currLen] = cnt % mod;
    }
    int knightDialer(int n) {
        vector<vector<char>> board({{'1', '2', '3'},
                                    {'4', '5', '6'},
                                    {'7', '8', '9'},
                                    {'*', '0', '#'}});
        int rows = board.size(), cols = board[0].size();

        long long cnt = 0;
        vector<vector<int>> dp(rows * cols, vector<int>(n + 1, -1));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (isdigit(board[i][j])) {
                    cnt = (cnt + backtrack(i, j, 1, n, dp, board)) % mod;
                }
            }
        }

        return cnt;
    }
};