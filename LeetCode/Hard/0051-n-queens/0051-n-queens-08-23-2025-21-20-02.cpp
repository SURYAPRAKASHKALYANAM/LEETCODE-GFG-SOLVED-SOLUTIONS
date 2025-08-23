class Solution {
public:
    vector<bool> col, dia1, dia2;
    void filled(int r, int c, int n, bool val) {
        dia1[n + (c - r)] = dia2[r + c] = col[c] = val;
    }
    bool isValid(int r, int c, int n) {
        return !dia1[n + (c - r)] && !dia2[r + c] && !col[c];
    }
    void fill(int r, vector<string>& board, vector<vector<string>>& ans,
              int n) {
        if (r == n) {
            ans.emplace_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(r, i, n)) {
                board[r][i] = 'Q';
                filled(r, i, n, true);
                fill(r + 1, board, ans, n);
                board[r][i] = '.';
                filled(r, i, n, false);
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        // your code goes here
        // row.resize(n, false);
        col.resize(n, false);
        dia1.resize(2 * n + 1, false);
        dia2.resize(2 * n + 1, false);
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        fill(0, board, ans, n);
        return ans;
    }
};