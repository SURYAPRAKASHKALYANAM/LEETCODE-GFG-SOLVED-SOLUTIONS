class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(),points.end());
        int c=1;
        int target=INT_MAX;
        for(auto i=0;i<points.size();i++)
        {
            if(target<points[i][0])
            {
                c++;
                target=points[i][1];
            }
            else
            {
                target=min(target,points[i][1]);
            }
            
        }
        return c;
    }
};