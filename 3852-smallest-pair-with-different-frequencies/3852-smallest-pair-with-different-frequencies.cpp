class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int,int> m;
        for(int i:nums) m[i]++;
        int x = -1,xfreq;
        for(auto [key,freq] : m){
            if(x==-1) {
                x = key;
                xfreq = freq;
            } else if(freq!=xfreq){
                return {x,key};
            }
        }
        return {-1,-1};
    }
};