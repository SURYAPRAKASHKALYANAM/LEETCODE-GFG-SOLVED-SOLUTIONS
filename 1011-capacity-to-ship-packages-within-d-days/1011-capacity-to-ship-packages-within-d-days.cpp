class Solution
{
    public:
        bool canship(vector<int> &weights, int days, int weight)
        {
            int total_days = 0;
            int pos = 0;
            while (pos < weights.size())
            {
                int pres = 0;
                while (pos < weights.size() && pres + weights[pos] <= weight) pres += weights[pos++];
                if (pres == 0) return false;
                total_days++;
            }
            return total_days <= days;
        }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int start = *max_element(weights.begin(), weights.end()),
            end = accumulate(weights.begin(), weights.end(), 0), mid = 0, res = 0;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (canship(weights, days, mid))
            {
                res = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return res;
    }
};