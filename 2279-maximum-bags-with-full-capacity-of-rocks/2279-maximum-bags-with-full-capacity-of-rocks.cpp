class Solution
{
    public:
        int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
        {
            int cnt = 0, n = capacity.size();
            priority_queue<int, vector < int>, greater < int>> q;
            for (int i = 0; i < n; i++)
            {
                if (capacity[i] - rocks[i]) q.push(capacity[i] - rocks[i]);
                else cnt++;
            }
            while (additionalRocks>0 && !q.empty())
            {
                auto it = q.top();
                if (it <= additionalRocks)
                {
                    additionalRocks -= it;
                    cnt++;
                    q.pop();
                }
                else break;
            }
            return cnt;
        }
};