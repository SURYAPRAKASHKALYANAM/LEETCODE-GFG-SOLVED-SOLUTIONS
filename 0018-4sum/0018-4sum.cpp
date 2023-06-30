class Solution
{
    public:
        vector<vector < int>> fourSum(vector<int> &nums, int target)
        {
            vector<vector < int>> sol;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); i++)
            {
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                    int k = j + 1, l = nums.size() - 1;
                    while (k < l)
                    {
                        long long sum = nums[i] + nums[j] ;
                            sum+= nums[k];
                            sum+= nums[l];
                        if (sum == target)
                        {
                            vector<int> tem = { nums[i],
                                nums[j],
                                nums[k],
                                nums[l]
                            };
                            sol.emplace_back(tem);
                            l--;
                            k++;
                            while (k < l && nums[k] == nums[k - 1]) k++;
                            while (k < l && nums[l] == nums[l + 1]) l--;
                        }
                        else if (sum > target) l--;
                        else k++;
                    }
                }
            }
            return sol;
        }
};