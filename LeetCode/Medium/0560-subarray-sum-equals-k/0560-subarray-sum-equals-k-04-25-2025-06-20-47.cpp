class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int c=0,ans=0;
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++)
        {
              c+=nums[i];
            if(c==k) ans++;
            if(m.find(c-k)!=m.end())
            {
                ans+=m[c-k];
            }
            m[c]++;
        }
        return ans;
        
    }
};