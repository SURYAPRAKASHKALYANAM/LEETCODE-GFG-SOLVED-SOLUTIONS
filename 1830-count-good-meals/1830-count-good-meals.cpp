class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> counts;
        int cnt = 0, mod = 1e9 + 7;
        sort(begin(deliciousness), end(deliciousness));
        for (auto i : deliciousness) {
            if(i!=0 && (i&(i-1))==0) cnt = (cnt+counts[0])%mod;
            if(i!=0){
                cnt = (cnt + counts[pow(2, (int)log2(i) + 1) - i]) % mod;
            }
            counts[i]++;
        }
        return cnt;
    }
};