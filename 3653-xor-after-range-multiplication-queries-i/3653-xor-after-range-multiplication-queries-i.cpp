class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int len = nums.size();
        long long mod = 1e9 + 7;
        for (auto it : queries) {
            int l = it[0], r = it[1], k = it[2], v = it[3];
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % mod;
            }
        }

        return accumulate(nums.begin(), nums.end(), 0LL, bit_xor<>());
    }
};