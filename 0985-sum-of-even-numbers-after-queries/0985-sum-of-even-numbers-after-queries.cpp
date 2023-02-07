class Solution
{
    public:
        vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector< int>> &queries)
        {
            vector<int> ans;
            int pre = 0;
            for (auto i: nums)
                if (!(abs(i) &1)) pre += i;
            for (auto i: queries)
            {
                if (abs(nums[i[1]]) &1)
                {
                    nums[i[1]] += i[0];
                    if (!(abs(nums[i[1]]) &1)) pre += nums[i[1]];
                }
                else
                {
                    pre -= nums[i[1]];
                    nums[i[1]] += i[0];
                    if (!(abs(nums[i[1]]) &1)) pre += nums[i[1]];
                }
                ans.emplace_back(pre);
            }
            return ans;
        }
};