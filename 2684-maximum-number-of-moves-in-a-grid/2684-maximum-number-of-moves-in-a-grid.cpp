class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        int dr[]={-1,0,1};
        int max_moves=0,prev=0;
        for(int col=1;col<n;col++)
        {
            bool change=0;
            for(int row=0;row<m;row++)
            {
                for(int i=0;i<3;i++)
                {
                    int c=col-1,r=row+dr[i];
                    if(c>=0 && r<m && r>=0 && grid[r][c]<grid[row][col])
                    {
                        change=1;
                        dp[row][col]=max(dp[r][c]+1,dp[row][col]);
                        max_moves=max(max_moves,dp[row][col]);
                    }
                    // else dp[row][col]=0;
                }
            }
            // if(!change) break; 
            // cout<<max_moves<<" "<<col<<endl;
            if(prev==max_moves) break;
            prev=max_moves;
        }
        return max_moves;
    }
};








