class Solution
{
    public:
        int sumOfBeauties(vector<int> &nums)
        {
            int min_array[nums.size()];
            memset(min_array, 0, nums.size());
            min_array[nums.size() - 1] = nums.back();
            int max_array[nums.size()];
            memset(max_array, 0, nums.size());
            max_array[0] = nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                max_array[i] = max(max_array[i - 1], nums[i]);
                min_array[nums.size() - 1 - i] = min(min_array[nums.size() - i], nums[nums.size() - 1 - i]);
            }
            int c = 0;
            for (int i = 1; i <= nums.size() - 2; i++)
            {
                if (nums[i] > max_array[i - 1] && nums[i] < min_array[i + 1]) c += 2;
                else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) c += 1;
            }
            return c;
        }
};