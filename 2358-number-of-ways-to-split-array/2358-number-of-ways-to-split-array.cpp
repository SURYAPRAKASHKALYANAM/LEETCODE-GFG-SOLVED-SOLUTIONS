class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        vector<long long> pref(n, 0);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + nums[i];
        for (int i = 0; i < n - 1; i++)
            if (pref[i] >= (pref[n - 1] - pref[i]))
                cnt++;
        return cnt;
    }
};