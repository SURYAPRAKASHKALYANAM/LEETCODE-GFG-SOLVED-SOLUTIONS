class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums) m[i]=1;
        sort(nums.begin(),nums.end());
        int l=nums.size()-1;
        while(l>=0 && nums[l]>0)
        {
            if(m[-nums[l]]==1)  return nums[l];
            l--;
        }
        return -1;
    }
};