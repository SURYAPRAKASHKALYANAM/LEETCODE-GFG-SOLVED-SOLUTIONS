class Solution
{
    public:
        int minSubarray(vector<int> &nums, int p)
        {
            int pre = 0, s = 0, min_len = INT_MAX;
            unordered_map<int, int> pos;
            for (auto i = 0; i < nums.size(); i++)
            {
                pre = (pre + nums[i]) % p;
            }
            pos[0] = -1;
            for (auto i = 0; i < nums.size(); i++)
            {
                s = (s + nums[i]) % p;
                pos[s] = i;
                int rem = (s - pre + p) % p;
                if (pos.find(rem) != pos.end()) min_len = min(min_len, i - pos[rem]);
            }
            return min_len >= nums.size() ? -1 : min_len;
        }
};