#define pi pair<int,int>
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        priority_queue<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>>> q;
        q.push({0,{0,0}});
        vector<vector<int>> visited(m,vector<int> (n,0));
        visited[0][0]=1;
        int min_obst=INT_MAX;
        vector<pi> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(!q.empty())
        {
            auto it=q.top();q.pop();
            int obst=it.first,r=it.second.first,c=it.second.second;
            if(r==m-1 && c==n-1 && min_obst>obst)  min_obst=obst;
            for(auto [dx,dy]:d)
            {
                int row=r+dx,col=c+dy;
                if(row>=0 && row<m && col>=0 && col<n && !visited[row][col])
                {
                    visited[row][col]=1;
                    q.push({obst+grid[row][col],{row,col}});
                }
            }
            
        }
        return min_obst;
    }
};