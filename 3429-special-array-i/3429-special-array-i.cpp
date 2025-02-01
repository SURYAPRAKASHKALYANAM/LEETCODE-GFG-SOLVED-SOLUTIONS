class Solution
{
    public:
        bool isArraySpecial(vector<int> &nums)
        {
            int n = nums.size();
            for (int i = 0; i < n; i++) nums[i] = nums[i] &1;
            if (n == 2) return nums[0] != nums[1];
            for (int i = 1; i < n - 1; i++)
            {
                if (!(!nums[i - 1] == nums[i] && !nums[i] == nums[i + 1])) return false;
            }
            return true;
        }
};