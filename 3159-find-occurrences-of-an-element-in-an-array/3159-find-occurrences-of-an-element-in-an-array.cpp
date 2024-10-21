class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ans,order ;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==x) order.emplace_back(i);
        }
        for(auto i:queries)
        {
            if(i<=order.size()) ans.emplace_back(order[i-1]);
            else ans.emplace_back(-1);
        }
        return ans;
    }
};