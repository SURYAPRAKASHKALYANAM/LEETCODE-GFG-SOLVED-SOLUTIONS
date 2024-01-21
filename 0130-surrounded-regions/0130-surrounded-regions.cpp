class Solution
{
    private:
        void dfs(int srow,int scol,vector<vector<char>> & board,vector<vector<int>> &visited)
        {
            visited[srow][scol]=1;
            int delrow[]={-1,0,1,0},delcol[]={0,1,0,-1};            
            int n = board.size(), m = board[0].size();
            for(int i=0;i<4;i++)
            {
                int row=srow+delrow[i],col=scol+delcol[i];
                if(row>=0 && row<n && col>=0 && col<m && board[row][col]=='O' && !visited[row][col])
                    dfs(row,col,board,visited);
            }

        }
    public:
        void solve(vector<vector < char>> &board)
        {
            int n = board.size(), m = board[0].size();
            vector<vector<int>> visited(n,vector<int>(m,0));
            for(int i=0;i<m;i++)
            {
                //first row
                if(board[0][i]=='O' && !visited[0][i]) dfs(0,i,board,visited);
                // last row
                if(board[n-1][i]=='O' && !visited[n-1][i]) dfs(n-1,i,board,visited);
            }
            for(int i=0;i<n;i++)
            {
                //first col
                if(board[i][0]=='O' && !visited[i][0]) dfs(i,0,board,visited);
                //last col
                if(board[i][m-1]=='O' && !visited[i][m-1]) dfs(i,m-1,board,visited);
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(board[i][j]=='O' && !visited[i][j]) board[i][j]='X';
                }
            }
        }
};