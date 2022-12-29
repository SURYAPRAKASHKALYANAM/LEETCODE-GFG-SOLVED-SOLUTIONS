class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        for(auto i:nums) m[i]++;
        int c=0;
        set<int> s(nums.begin(),nums.end());
        for(auto i:s)
        {
            if(k!=0)
            {  
                if(m[i+k])
                {
                    c++;
                    m[i+k]--;
                }
            }
            else
            {
                if(m[i]>1) 
                {
                    c++;
                    m[i]--;
                }
            }
        }
        return c;
    }
};