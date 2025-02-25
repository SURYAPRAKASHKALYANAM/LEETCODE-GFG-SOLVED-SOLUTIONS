class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n, 0), odd(n, 0);
        pref[0] = arr[0];
        int oddcnt = odd[0] = arr[0] & 1;
        for (int i = 1; i < n; i++) {
            pref[i] += pref[i - 1] + arr[i];
            oddcnt += (odd[i] = pref[i] & 1);
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