class Solution
{
    public:
        vector<int> sortedSquares(vector<int> &nums)
        {
            int begin = 0, end = nums.size() - 1, k = end;
            vector<int> result(end + 1);
            while (begin <= end)
            {
                if (nums[begin] *nums[begin] < nums[end] *nums[end])
                {
                    result[k--] = nums[end] *nums[end];
                    end--;
                }
                else
                {
                    result[k--] = nums[begin] *nums[begin];
                    begin++;
                }
            }
            return result;
        }
};