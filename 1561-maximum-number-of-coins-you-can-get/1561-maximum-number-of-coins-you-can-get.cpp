class Solution
{
    public:
        int maxCoins(vector<int> &piles)
        {
            sort(piles.begin(), piles.end());
            int sum = 0;
            int n = piles.size() - 2;
            int steps = piles.size() / 3;
            while (steps--)
            {
                sum += piles[n];
                n -= 2;
            }
            return sum;
        }
};