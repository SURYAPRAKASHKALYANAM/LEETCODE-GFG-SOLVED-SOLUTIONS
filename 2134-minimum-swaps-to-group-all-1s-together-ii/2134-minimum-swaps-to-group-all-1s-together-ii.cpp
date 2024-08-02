class Solution
{
    public:
        int minSwaps(vector<int> &nums)
        {
            int window = accumulate(nums.begin(), nums.end(), 0);
            int n = nums.size();
            for (int i = 0; i < n; i++) nums.emplace_back(nums[i]);
            int pres = 0, start = 0, end = 0, ans = INT_MAX;
            while (end < window) pres += nums[end++];
            while (end < nums.size())
            {
                ans = min(ans, window - pres);
                pres -= nums[start++];
                pres += nums[end++];
            }
            return ans;
        }
};