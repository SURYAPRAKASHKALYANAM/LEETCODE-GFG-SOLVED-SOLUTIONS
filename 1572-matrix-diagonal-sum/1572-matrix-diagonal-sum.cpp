class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int k=0;
        int s=0;
        for(int i=0;i<mat.size();i++)
        {
            if(k!=mat.size()-k-1)
                s+=mat[i][k]+mat[i][mat.size()-k-1];
            else
                s+=mat[i][k];
            k+=1;
            
        }
        return s;
    }
};