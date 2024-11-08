class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans,pref(nums.size());
        pref[0]=nums[0];
        for(int i=1;i<nums.size();i++) pref[i]=pref[i-1]^nums[i];
        int maxi=(1<<maximumBit)-1;
        for(int i=nums.size()-1;i>=0;i--) ans.emplace_back(pref[i]^maxi);
        return ans;
    }
};