class Solution {
public:
    vector<bool> col, dia1, dia2;
    void filled(int r, int c, int n, bool val) {
        dia1[n + (c - r)] = dia2[r + c] = col[c] = val;
    }
    bool isValid(int r, int c, int n) {
        return !dia1[n + (c - r)] && !dia2[r + c] && !col[c];
    }
    int fill(int r, vector<string>& board, int n) {
        if (r == n) {
            return 1;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (isValid(r, i, n)) {
                board[r][i] = 'Q';
                filled(r, i, n, true);
                cnt += fill(r + 1, board, n);
                board[r][i] = '.';
                filled(r, i, n, false);
            }
        }
        return cnt;
    }
    int totalNQueens(int n) {
        // your code goes here
        // row.resize(n, false);
        col.resize(n, false);
        dia1.resize(2 * n + 1, false);
        dia2.resize(2 * n + 1, false);
        vector<string> board(n, string(n, '.'));
        return fill(0, board, n);
    }
};