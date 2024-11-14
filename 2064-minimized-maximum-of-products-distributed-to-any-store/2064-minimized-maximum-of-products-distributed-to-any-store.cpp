class Solution
{
    public:
    bool canshare(int max_prod, vector<int> &nums, int shops)
    {
        if (max_prod == 0) return false;
        int shops_distributed = 0, n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            shops_distributed += nums[i] / max_prod + ((nums[i] % max_prod) > 0);
        }
        return shops_distributed <= shops;
    }
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int start = 0, end = *max_element(quantities.begin(), quantities.end()), res = 0, mid;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (canshare(mid, quantities, n))
            {
                res = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return res;
    }
};