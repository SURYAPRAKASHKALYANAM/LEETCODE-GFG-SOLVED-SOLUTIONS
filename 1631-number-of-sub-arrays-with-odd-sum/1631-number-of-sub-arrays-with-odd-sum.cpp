class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> odd(n, 0);
        int sum = 0;
        int oddcnt = 0;
        for (int i = 0; i < n; i++) {
            sum+=arr[i];
            oddcnt += (odd[i] = sum & 1);
        }
        int evencnt = n - oddcnt;
        int ans = oddcnt, mod = 1e9 + 7;
        oddcnt -= (odd[0] & 1);
        evencnt -= !(odd[0] & 1);
        for (int i = 1; i < n; i++) {
            if (odd[i - 1] & 1) {
                ans += evencnt;
            } else {
                ans += oddcnt;
            }
            oddcnt -= (odd[i] & 1);
            evencnt -= !(odd[i] & 1);
            ans %= mod;
        }
        return ans;
    }
};