class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {
            int pre[nums.size()], post[nums.size()];
            memset(pre, 1, nums.size());
            memset(post, 1, nums.size());
            int n = nums.size();
            pre[0] = nums[0];
            post[n - 1] = nums[n - 1];
            for (int i = 1; i < n; i++)
            {
                pre[i] = pre[i - 1] *nums[i];
                post[n - i - 1] = post[n - i] *nums[n - i - 1];
            }
            vector<int> ans(n, 0);
            ans[0] = post[1];
            ans[n - 1] = pre[n - 2];
            for (int i = 1; i < n - 1; i++) ans[i] = pre[i - 1] *post[i + 1];
            return ans;
        }
};