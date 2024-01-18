class Solution {
public:
      void dfs(int srow,int scol,vector<vector<int>> & board,vector<vector<int>> &visited)
        {
            visited[srow][scol]=1;
            int delrow[]={-1,0,1,0},delcol[]={0,1,0,-1};            
            int n = board.size(), m = board[0].size();
            for(int i=0;i<4;i++)
            {
                int row=srow+delrow[i],col=scol+delcol[i];
                if(row>=0 && row<n && col>=0 && col<m && board[row][col]==0 && !visited[row][col])
                    dfs(row,col,board,visited);
            }

        }
    int closedIsland(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            //first row
            if(board[0][i]==0 && !visited[0][i]) dfs(0,i,board,visited);
            // last row
            if(board[n-1][i]==0 && !visited[n-1][i]) dfs(n-1,i,board,visited);
        }
        for(int i=0;i<n;i++)
        {
            //first col
            if(board[i][0]==0 && !visited[i][0]) dfs(i,0,board,visited);
            //last col
            if(board[i][m-1]==0 && !visited[i][m-1]) dfs(i,m-1,board,visited);
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==0 && !visited[i][j])
                {
                    cnt++;
                    dfs(i,j,board,visited);
                }
            }
        }
        return cnt;
    }
};