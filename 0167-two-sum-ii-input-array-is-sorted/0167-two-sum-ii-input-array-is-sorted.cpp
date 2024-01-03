class Solution
{
    public:
        vector<int> twoSum(vector<int> &in, int k)
        {
            int low = 0, high = in .size() - 1;
            while (low < high)
            {
                int s = in[low] + in[high];
                if (s == k) return {low + 1,high + 1};
                if (s < k) low++;
                else high--;
            }
            return { -1,-1 };
        }
};