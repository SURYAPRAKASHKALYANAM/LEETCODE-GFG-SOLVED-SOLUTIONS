class Solution {
public:
    static bool comp(vector<int> a,vector<int> b)
    {
        // if(a[0]=b[0]) return a[1]>b[1];
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        
        sort(intervals.begin(),intervals.end(),comp);
        int c=0,i=0,j=1;
        while(i<intervals.size() && j<intervals.size())
        {
            if(intervals[i][1]>intervals[j][0])
            {
                c++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return c;
        
    }
};