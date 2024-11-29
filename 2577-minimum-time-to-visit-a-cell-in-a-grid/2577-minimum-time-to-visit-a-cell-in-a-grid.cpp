class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>  q;
        q.push({0,{0,0}});
        queue<pair<int,int>> q1;
        visited[0][0]=1;
        int dx[]={0,-1,1,0},dy[]={-1,0,0,1};
        while(!q.empty())
        {
            auto it=q.top();q.pop();
            int currt=it.first,r=it.second.first,c=it.second.second;
            if(r==m-1 && c==n-1) return currt;
            int stepped=0;
            for(int i=0;i<4;i++)
            {
                int row=r+dx[i],col=c+dy[i];
                if(row>=0 && row<m && col>=0 &&  col<n)
                {
                    if((currt+1)>=grid[row][col])
                    {
                        if(!visited[row][col])
                        {
                            stepped++;
                            q.push({currt+1,{row,col}});
                            visited[row][col]=1;
                        }
                    }
                    else q1.push({row,col});
                }
            }
            if(q.size())
            {
                while(!q1.empty())
                {
                    int row=q1.front().first,col=q1.front().second;
                    q1.pop();
                    int steps=grid[row][col]-currt+1;
                    q.push({grid[row][col]+(steps%2),{row,col}});
                    visited[row][col]=1;
                }
            }
            
        }
        return -1;
    }
};