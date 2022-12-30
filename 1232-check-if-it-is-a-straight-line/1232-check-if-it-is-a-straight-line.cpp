class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        if(coordinates[1][0]-coordinates[0][0]==0)
        {
           for(int i=2;i<coordinates.size();i++)
           {
               if(coordinates[i][0]-coordinates[0][0]!=0)return false;
           }
            return true;
        }
        float m=(float)(coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]);
        for(int i=2;i<coordinates.size();i++)
        {
            // cout<<coordinates[i][1]-coordinates[0][1]<<" "<<m<<coordinates[i][0]-coordinates[0][0];
            if((coordinates[i][1]-coordinates[0][1])!=m*(coordinates[i][0]-coordinates[0][0])) return false;
        }
        return true;
    }
};