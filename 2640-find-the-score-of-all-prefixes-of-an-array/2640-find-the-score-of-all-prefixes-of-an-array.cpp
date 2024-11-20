class Solution
{
    public:
        vector < long long > findPrefixScore(vector<int> &nums)
        {
            vector < long long > ans(nums.size(), 0);
            int maxi = nums[0];
            ans[0] = maxi + nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                maxi = max(maxi, nums[i]);
                ans[i] = ans[i - 1] + nums[i] + maxi;
            }
            return ans;
        }
};