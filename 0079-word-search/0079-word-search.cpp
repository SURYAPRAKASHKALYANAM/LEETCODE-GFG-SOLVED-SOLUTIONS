class Solution
{
    public:
        bool dfs(int row, int col, int pos, string word, vector<vector <char>> &board,int n,int m)
        {
            if (pos >= word.size()) return true;
            int delrow[]={-1,0,1,0},delcol[]={0,1,0,-1};
            char c=board[row][col];
            board[row][col]='#';
            for (int i = 0; i < 4; i++)
            {
                int curr = row + delrow[i], currc = col + delcol[i];
                if (curr >= 0 && curr < n && currc >= 0 && currc < m
                    && board[curr][currc] == word[pos])
                {
                    if (dfs(curr, currc, pos + 1, word, board,n,m)) return true;
                }
            }
            board[row][col]=c;
            return false;
        }
    bool exist(vector<vector < char>> &board, string word)
    {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0] && dfs(i, j, 1, word, board,n,m) )
                {
                    return true;
                }
            }
        }
        return false;
    }
};