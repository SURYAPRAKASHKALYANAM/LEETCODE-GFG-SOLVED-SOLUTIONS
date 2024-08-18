class Solution
{
    public:
        bool checkValidGrid(vector<vector < int>> &grid)
        {
            int curr_step = 1, n = grid.size();
           	int delrow[]={1,-1};
           	int delcol[]={2,-2};
            int startr=0,startcol=0;
            if(grid[startr][startcol]!=0) return false;
            queue<pair<int, int>> q;
           	q.push({startr,startcol});
            while (!q.empty())
            {
                int r=q.front().first,c=q.front().second;
                q.pop();
                for (int row = 0; row<2; row++)
                {
                    bool flag=0;
                    for (int col = 0; col<2; col++) 
                    {
                        int curr=r+delrow[row],curc=c+delcol[col];
                        if(curr>=0 && curr<n && curc>=0 && curc<n )
                        {
                            if(grid[curr][curc]==curr_step)
                            {
                                q.push({curr,curc});
                                curr_step++;
                                flag=1;
                                break;
                            }
                        }
                        curr=r+delcol[col],curc=c+delrow[row];
                        if(curr>=0 && curr<n && curc>=0 && curc<n )
                        {
                            if(grid[curr][curc]==curr_step)
                            {
                                q.push({curr,curc});
                                curr_step++;
                                flag=1;
                                break;
                            }
                        }
                        
                    }
                    if(flag) break;
                }
            }
            return curr_step==(n*n);
        }
};