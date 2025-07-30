class Solution
{
    public:
        int longestSubarray(vector<int> &nums)
        {
            int max_ele = *max_element(nums.begin(), nums.end());
            int max_sub = 0, curr_len = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == max_ele) curr_len++;
                else curr_len = 0;
                max_sub = max(max_sub, curr_len);
            }
            return max_sub;
        }
};