class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
           	//better one but not optimal solution
           	//set<vector < int>> s;
           	// for (int i = 0; i < nums.size(); i++)
           	// {
           	//     map<int, int> m;
           	//     for (int j = i + 1; j < nums.size(); j++)
           	//     {
           	//         int rem = -(nums[i] + nums[j]);
           	//         if (m[rem])
           	//         {
           	//             vector<int> temp = { nums[i],
           	//                 nums[j],
           	//                 rem
           	//             };
           	//             sort(temp.begin(), temp.end());
           	//             s.insert(temp);
           	//         }
           	//         m[nums[j]] = 1;
           	//     }
           	// }

           	//two pointers otimal solution
            vector<vector < int>> sol;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); i++)
            {
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                int start = nums[i];
                int left = i + 1, right = nums.size() - 1;
                while (left < right)
                {
                    if ((nums[left] + nums[right] + start) == 0)
                    {
                        vector<int> temp = { start,
                            nums[left],
                            nums[right]
                        };
                        left++;
                        right--;
                       	// s.insert(temp);
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                        sol.emplace_back(temp);
                    }
                    else if ((nums[left] + nums[right] + start) > 0) right--;
                    else left++;
                }
            }
           	// vector<vector < int>> sol(s.begin(), s.end());
            return sol;
        }
};