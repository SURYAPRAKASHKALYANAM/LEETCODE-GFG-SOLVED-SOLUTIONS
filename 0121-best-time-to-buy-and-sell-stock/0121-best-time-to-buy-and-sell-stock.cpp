class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int ans = INT_MIN, dif;
            int minimalprice = prices[0];
            for (int i = 1; i < prices.size(); i++)
            {
                dif = prices[i] - minimalprice;	//find the cost of stocks
                ans = max(ans, dif);	// keep track of max profit
                minimalprice = min(prices[i], minimalprice);
            }
           	//return max profit 
            return (ans < 0) ? 0 : ans;
        }
};