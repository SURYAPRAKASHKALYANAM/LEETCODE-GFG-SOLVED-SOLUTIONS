class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) 
    {
        vector<int> ans(nums.size(),0),finall;
        map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++)
        {
            int p=0,k=nums[i];
            if(nums[i]==0) m[mapping[nums[i]]].emplace_back(0);
            else
            {
                while(nums[i])
                {
                    ans[i]+=(mapping[nums[i]%10]*pow(10,p++));
                    nums[i]=nums[i]/10;
                }
                m[ans[i]].emplace_back(k);
            }
        }
        for(auto i:m)
        {
            cout<<i.first<<" ";
            for(auto j:i.second) finall.emplace_back(j);
        }
        return finall;
    }
};