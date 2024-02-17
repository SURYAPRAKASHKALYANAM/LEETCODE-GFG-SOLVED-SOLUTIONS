class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i;
        int sum=0;
        priority_queue<int,vector<int>,greater<int>> q;
        for(i=0;i<heights.size()-1;i++)
        {
            int diff=heights[i+1]-heights[i];
            if(diff<=0) continue;
            if(q.size()<ladders)
            {
                q.push(diff);
            }
            else if(q.size())
            {
                int smallest=q.top();
                if(smallest<diff)
                {
                    q.pop();
                    q.push(diff);
                    sum+=smallest;
                }
                else sum+=diff;
                if(sum>bricks) break;
            }
            else
            {
                if(diff<=bricks) bricks-=diff;
                else break;
            }
            
        }
        return i;
    }
};