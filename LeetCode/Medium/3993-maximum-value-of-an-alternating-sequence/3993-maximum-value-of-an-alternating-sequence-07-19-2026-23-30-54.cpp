class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long ans = 0LL;
        if(n==1) return s;
        int len = n / 2;
        ans = s + ((m-1) * 1LL * len) + 1LL;
        return ans;
    }
};