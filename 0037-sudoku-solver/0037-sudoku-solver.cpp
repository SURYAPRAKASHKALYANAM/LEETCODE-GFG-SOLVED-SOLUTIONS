class Solution {
public:
    bool issafe(char c,int row,int col,vector<vector<char>> &board)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c) return false;
            if(board[i][col]==c) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;

        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        for(int row=0;row<9;row++)
        {
            for(int col=0;col<9;col++)
            {
                if(board[row][col]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(issafe(c,row,col,board))
                        {
                            board[row][col]=c;
                            if(solve(board)==true) return true;
                            else board[row][col]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board);
    }
};