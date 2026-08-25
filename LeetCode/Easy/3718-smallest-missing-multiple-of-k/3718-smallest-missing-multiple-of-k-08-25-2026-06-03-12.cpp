class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]=1;
        int p=k;
        while(true){
            if(!mp[k]) break;
            k+=p;
        }
        return k;
    }
};