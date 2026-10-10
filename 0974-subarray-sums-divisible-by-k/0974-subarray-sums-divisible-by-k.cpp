class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int curr_sum = 0, cnt = 0;
        vector<int> seen(k);
        seen[0] = 1;
        int pref = 0;
        for (int i = 0; i < nums.size(); i++) {
            pref += nums[i];
            pref %= k;
            cnt += (seen[(pref + k) % k]);
            seen[(pref + k) % k]++;
        }
        return cnt;
    }
};