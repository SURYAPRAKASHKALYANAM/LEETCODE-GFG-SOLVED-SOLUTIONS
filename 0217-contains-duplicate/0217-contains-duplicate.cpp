class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums)
        {
            if(m[i]) return true;
            m[i]++;
        }
        return false;
    }
};