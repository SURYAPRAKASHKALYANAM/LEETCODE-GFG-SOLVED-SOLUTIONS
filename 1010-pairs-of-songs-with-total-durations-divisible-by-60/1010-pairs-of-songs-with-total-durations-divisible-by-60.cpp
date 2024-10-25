class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt=0;
        unordered_map<int,int> m;
        for(int i:time)
        {
            int rem=i%60;
            if(rem)
            {
                cnt+=m[60-rem];
            }
            else cnt+=m[rem];
            m[rem]++;
        }
        return cnt;
    }
};