class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    if (i - 1 < 0 && j - 1 < 0) {
                        cnt++;
                    } else if (i - 1 < 0) {
                        if (board[i][j - 1] == 'X')
                            continue;
                        cnt++;
                    } else if (j - 1 < 0) {
                        if (board[i - 1][j] == 'X')
                            continue;
                        cnt++;
                    } else {
                        cnt +=(board[i][j - 1] != 'X' && board[i - 1][j] != 'X');
                    }
                }
            }
        }
        return cnt;
    }
};