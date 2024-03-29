class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &nums)
        {
            vector<vector < int>> sol;
            sort(nums.begin(), nums.end());
           	// int start, end;
           	// for (int i = 0; i < nums.size(); i++)
           	// {
           	//     start = nums[i][0], end = nums[i][1];
           	//     if (!sol.empty())
           	//     {
           	//         if (start <= sol.back()[1]) continue;
           	//     }
           	//     for (int j = i + 1; j < nums.size(); j++)
           	//     {
           	//         if (nums[j][0] <= end) end = max(end, nums[j][1]);
           	//         else break;
           	//     }
           	//     sol.emplace_back(std::vector<int>{start,end});
           	// }

           	//optimal 1.check for merging case if not merged push checking pair else updtae sol.back end val with max val

            for (int i = 0; i < nums.size(); i++)
            {
                if (sol.empty() || nums[i][0] > sol.back()[1]) sol.emplace_back(nums[i]);
                else
                {
                    sol.back()[1] = max(sol.back()[1], nums[i][1]);
                }
            }
            return sol;
        }
};