class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> minEff(n,vector<int> (m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        minEff[0][0]=0;
        int delrow[]={-1,0,1,0},delcol[]={0,1,0,-1};
        while(!q.empty())
        {
            auto it = q.top();
            q.pop();
            int pasEff=it.first;
            int r=it.second.first,c=it.second.second;
            if(r==n-1 && c==m-1) break;
            for(int i=0;i<4;i++)
            {
                int row=r+delrow[i],col=c+delcol[i];
                if(row>=0 && row<n && col>=0 && col<m)
                {
                    int presEff=max(abs(heights[r][c]-heights[row][col]),pasEff);
                    if(presEff < minEff[row][col] )
                    {
                        minEff[row][col]=presEff;
                        q.push({presEff,{row,col}});
                    }
                }
            }
        }
        return minEff[n-1][m-1];
    }
};