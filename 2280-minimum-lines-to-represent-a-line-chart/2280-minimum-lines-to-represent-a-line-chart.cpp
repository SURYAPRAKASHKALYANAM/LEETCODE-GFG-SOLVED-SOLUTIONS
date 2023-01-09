class Solution {
public:
    int minimumLines(vector<vector<int>>& points) 
    {
        sort(points.begin(),points.end());
        long double d,prev=FLT_MAX;
        int c=0;
        for(int i=0;i<points.size()-1;i++)
        {
            if(points[i+1][0]-points[i][0]==0) d=INT_MAX;
            else d=(long double)(points[i+1][1]-points[i][1])/(points[i+1][0]-points[i][0]);
            if(d!=prev)
            {
                c++;
                prev=d;
            }
        }
        return c;
    }
};