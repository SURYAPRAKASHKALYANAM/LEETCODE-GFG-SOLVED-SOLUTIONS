class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> min_height_to_reach(n,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> min_heap;
        min_heap.push({grid[0][0],{0,0}});
        min_height_to_reach[0][0]=grid[0][0];
        int delrow[]={-1,0,1,0},delcol[]={0,1,0,-1};
        while(!min_heap.empty())
        {
            auto it=min_heap.top();
            min_heap.pop();
            int pastHeight=it.first;
            int r=it.second.first;
            int c=it.second.second;
            for(int i=0;i<4;i++)
            {
                int row=r+delrow[i],col=c+delcol[i];
                if(row>=0 && row<n && col>=0 && col<n)
                {
                    int present_height=max(pastHeight,grid[row][col]);
                    if(present_height<min_height_to_reach[row][col])
                    {
                        min_height_to_reach[row][col]=present_height;
                        min_heap.push({min_height_to_reach[row][col],{row,col}});
                    }
                }
            }
        }
        return min_height_to_reach[n-1][n-1];
    }
};