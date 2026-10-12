class Solution {
public:
    bool find(vector<int> nums,int k)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==k)
                return true;
        }
        return false;
    }
    vector<int> intersection(vector<vector<int>>& nums)
    {
        vector <int> sol;
        for(int i=0;i<nums[0].size();i++)
        {
            int c=1;
            for(int j=1;j<nums.size();j++)
            {
                if(find(nums[j],nums[0][i]))
                    c+=1;
                
            }
            if(c==nums.size())
                sol.emplace_back(nums[0][i]);
        } 
        sort(sol.begin(),sol.end());
      return sol;  
        
    }
};