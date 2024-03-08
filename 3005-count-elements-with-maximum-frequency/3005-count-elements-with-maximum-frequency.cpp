class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        int max_freq=0,cnt=0;
        for(auto i:nums)
        {
            m[i]++;
            max_freq=max(max_freq,m[i]);
        }
        for(auto i:m)
        {
            if(i.second==max_freq) cnt+=max_freq;
        }
        return cnt;
    }
};