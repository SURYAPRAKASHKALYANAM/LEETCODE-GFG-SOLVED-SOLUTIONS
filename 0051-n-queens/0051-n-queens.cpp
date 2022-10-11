class Solution {
public:
    void solve(int col,vector<string> &board,vector<int> &left,vector<int> &leftld,vector<int> &leftud,int n,vector<vector<string>> &ans)
    {
        if(col==n)
        {
            ans.emplace_back(board);
            return;
        }
        for(int row = 0;row<n;row++)
        {
            if(left[row]==0 && leftld[row+col]==0 && leftud[n-1+row-col]==0)
            {
                board[row][col]='Q';
                left[row]=1;
                leftld[row+col]=1;
                leftud[n-1+row-col]=1;
                solve(col+1,board,left,leftld,leftud,n,ans);
                board[row][col]='.';
                left[row]=0;
                leftud[n-1+row-col]=0;
                leftld[row+col]=0;

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++)
    {
        board[i]=s;
    }
    vector<int> left(n,0),leftld(2*n-1,0),leftud(2*n-1,0);
    solve(0,board,left,leftld,leftud,n,ans);
     return ans;   
    }
};