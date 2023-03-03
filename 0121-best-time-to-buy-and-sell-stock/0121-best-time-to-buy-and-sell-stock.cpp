class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int ans = INT_MIN, dif;
            int k = prices[0];
            for (int i = 1; i < prices.size(); i++)
            {
                dif = prices[i] - k;
                if (dif < 0) k = prices[i];
                else ans = max(ans, dif);
            }
            if (ans == INT_MIN) return 0;
            return ans;
        }
};