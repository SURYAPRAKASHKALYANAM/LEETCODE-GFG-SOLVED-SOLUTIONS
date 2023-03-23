class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int ans=0,maxi=0;
        for(auto i:gain)
        {
          maxi+=i;
            ans=max(maxi,ans);
        }
        return ans;
    }
};