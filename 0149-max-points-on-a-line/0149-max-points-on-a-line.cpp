class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        if(points.size()==1) return 1;
        // unordered_map<float,int> m;
        int maxi=INT_MIN;
        for(int i=0;i<points.size();i++)
        {
            unordered_map<float,int> m;
            float d;
            for(int j=i+1;j<points.size();j++)
            { 
                if(points[j][0]-points[i][0]==0) d=INT_MAX;
                else  d=(float)(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);
                m[d]++;
                maxi=max(maxi,m[d]);
            }
        }
        return maxi+1;
    }
};