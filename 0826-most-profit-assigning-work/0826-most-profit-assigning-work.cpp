class Solution
{
    public:
        int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector< int > &worker)
        {
            vector<pair<int, int>> v;
            int max_profit = 0;
            for (int i = 0; i < difficulty.size(); i++) v.push_back({ difficulty[i], profit[i] });
            sort(v.begin(), v.end());
            sort(worker.begin(), worker.end());
            int i = 0, j = 0;
            while (i < worker.size())
            {
                int maxi = 0;
                j = 0;
                while (j < v.size() && v[j].first <= worker[i]) maxi = max(maxi, v[j++].second);
                i++;
                max_profit += maxi;
            }
            return max_profit;
        }
};