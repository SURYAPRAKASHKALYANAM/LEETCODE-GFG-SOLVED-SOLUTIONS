class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums) m[i]++;
        nums.clear();
        for(auto i:m)
        {
            if(i.second) for(auto ii=0;ii<i.second;ii++) nums.emplace_back(i.first);
        }
        return nums;
        
    }
};