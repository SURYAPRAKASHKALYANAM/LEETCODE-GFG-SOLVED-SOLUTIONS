class Solution
{
    public:
        vector<int> resultsArray(vector<int> &nums, int k)
        {
            int start = 0, end = 0, n = nums.size();
           	// if (n == 1 || k == 1) return nums;
            vector<int> ans(n - k + 1);
            while (end < n)
            {
                while (end + 1 < n && nums[end] + 1 == nums[end + 1])
                {
                    if (end - start + 1 == k) ans[start++] = nums[end];
                    end++;
                }
                if (end - start + 1 == k) ans[start++] = nums[end];
                while (end + 1 < n && start <= end && nums[end] + 1 != nums[end + 1] && start < ans.size())
                    ans[start++] = -1;
                end++;
            }
            return ans;
        }
};