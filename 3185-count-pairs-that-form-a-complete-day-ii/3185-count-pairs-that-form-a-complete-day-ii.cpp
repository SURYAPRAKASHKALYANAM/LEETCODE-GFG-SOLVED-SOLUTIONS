class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long cnt=0;
        unordered_map<int,int> m;
        for(int i:hours)
        {
            int rem=i%24;
            if(rem)
            {
                cnt+=m[24-rem];
            }
            else cnt+=m[rem];
            m[rem]++;
        }
        return cnt;
    }
};