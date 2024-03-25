class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int pos=abs(nums[i])-1;
            if(nums[pos]<0) ans.emplace_back(abs(nums[i]));
            nums[pos]=-nums[pos];
        }
        
        return ans;
        
    }
};