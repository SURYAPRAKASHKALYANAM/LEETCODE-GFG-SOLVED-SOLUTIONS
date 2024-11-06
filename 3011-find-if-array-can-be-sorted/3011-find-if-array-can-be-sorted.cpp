
#define find __builtin_popcount
class Solution
{
    public:
        bool canSortArray(vector<int> &nums)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = 1; j < nums.size(); j++)
                    if (nums[j - 1] > nums[j] && find(nums[j - 1]) == find(nums[j])) swap(nums[j - 1], nums[j]);
            }
            for (int i = 1; i < nums.size(); i++)   if (nums[i] < nums[i - 1]) return false;
            return true;
        }
};