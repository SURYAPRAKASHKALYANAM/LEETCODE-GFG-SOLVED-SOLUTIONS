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
        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
        for (int i = 0; i < 8; i++) {
            int x = r + dx[i], y = c + dy[i];
            if (x < rows && x >= 0 && y < cols && y >= 0 &&
                isdigit(board[x][y])) {
                cnt = (cnt + backtrack(x, y, currLen + 1, n, dp, board)) % mod;
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