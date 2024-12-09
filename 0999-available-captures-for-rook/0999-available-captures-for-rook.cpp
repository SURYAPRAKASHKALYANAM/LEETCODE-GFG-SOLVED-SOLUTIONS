class Solution {
public:
    int find(vector<vector<char>>& board,int row,int col,int m,int n,int dx,int dy)
    {
        if((row<0 || row>=m) || (col<0 || col>=n) || board[row][col]=='B') return 0;
        if(board[row][col]=='p') return 1;
        return find(board,row+dx,col+dy,m,n,dx,dy);
    }
    int numRookCaptures(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        int posr,posj;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++) if(board[i][j]=='R') {posr=i,posj=j;break;}
        }
        int cnt=0;
        cnt+=find(board,posr,posj,m,n,0,1);
        cnt+=find(board,posr,posj,m,n,0,-1);
        cnt+=find(board,posr,posj,m,n,1,0);
        cnt+=find(board,posr,posj,m,n,-1,0);
        return cnt;
    }
};