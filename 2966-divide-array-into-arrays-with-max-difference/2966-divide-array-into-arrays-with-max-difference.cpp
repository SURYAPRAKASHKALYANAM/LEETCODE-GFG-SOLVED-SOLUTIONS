class Solution
{
    public:
        vector<vector < int>> divideArray(vector<int> &nums, int k)
        {
            int n = nums.size();
            vector<vector < int>> ans;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < n; i += 3)
            {
                vector<int> sub;
                for (int j = 0; j < 3; j++)
                {
                    if (sub.empty()) sub.emplace_back(nums[i + j]);
                    else if (nums[i + j] - sub[0] <= k) sub.emplace_back(nums[i + j]);
                    else return {};
                }
                ans.emplace_back(sub);
            }
            return ans;
        }
};