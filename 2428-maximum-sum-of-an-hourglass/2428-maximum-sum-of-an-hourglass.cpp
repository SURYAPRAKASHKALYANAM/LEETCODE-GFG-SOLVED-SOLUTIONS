class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),maxi=0;
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                maxi=max(maxi,grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1]+grid[i][j]+
                         grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1]);
            }
        }
        return maxi;
    }
};