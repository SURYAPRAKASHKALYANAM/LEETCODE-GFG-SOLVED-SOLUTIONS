class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long cnt = 0, n = nums.size();
        // vector<int> pref(n);
        // pref[0] = (nums[0] % modulo) == k;
        // for (int i = 1; i < n; i++) {
        //     pref[i] = pref[i - 1] + ((nums[i] % modulo) == k);
        // }
        unordered_map<int, int> seen;
        seen[0] = 1;
        int pref = 0;
        for (int i = 0; i < n; i++) {
            pref += ((nums[i] % modulo) == k);
            pref %= modulo;
            cnt += seen[(pref + modulo - k) % modulo];
            seen[pref]++;
        }
        return cnt;
    }
};