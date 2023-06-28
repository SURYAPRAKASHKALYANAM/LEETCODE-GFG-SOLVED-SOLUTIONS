class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int> ans;
        //better TC: O(N*LOG(N)+O(N)) SC:O(N)
        map<int,int> m;
        for(auto i:nums) m[i]++;
        for(auto i:m)
        {
            if(i.second>nums.size()/3) ans.emplace_back(i.first);
            if(ans.size()==2) break;
        }
        
        
        //OPTIMAL : 
        return ans;
    }
};