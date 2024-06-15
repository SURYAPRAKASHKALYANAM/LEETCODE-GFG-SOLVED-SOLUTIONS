class Solution
{
    public:
        int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
        {
            vector<pair<int, int>> q;
            for (int i = 0; i < profits.size(); i++) q.push_back({ capital[i],profits[i]});
            priority_queue<int> pq;
            sort(q.begin(), q.end());
            int i = 0;
            while (k && !q.empty())
            {
                int maxi = 0;
                while (i < q.size() && q[i].first <= w)
                {
                    pq.push(q[i].second);
                   	// maxi = max(maxi, q.top().second);
                   	// q.pop();
                    i++;
                }
               	// w += maxi;
                if (pq.size())
                {
                    w += pq.top();
                    pq.pop();
                }
                k--;
            }
            return w;
        }
};