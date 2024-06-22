class Solution
{
    public:
        bool checkSubarraySum(vector<int> &nums, int k)
        {
            int curr_sum = 0;
            unordered_map<int, int> m;
            m[0] = -1;
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i] == 0 && nums[i + 1] == 0) return true;
            }
            for (int i = 0; i < nums.size(); i++)
            {
                curr_sum += nums[i];
                curr_sum = curr_sum % k;
                if (m.find(curr_sum) != m.end())
                {
                    if ((i - m[curr_sum]) > 1) return true;
                }
                else m[curr_sum] = i;
            }
            return false;
        }
};