class Solution
{
    public:
        int minOperations(vector<int> &nums, int k)
        {

            priority_queue<long, vector < long>, greater < long>> q;
            for (auto i: nums)
            {
                if (i < k)
                    q.push(i);
            }
            int cnt = 0;
            while (q.size() >= 2)
            {
                int x = q.top();
                q.pop();
                int y = q.top();
                q.pop();
                long next = min(x, y) *2L + max(x, y);
                if (next < k)
                    q.push(next);
                cnt++;
            }
            return cnt + (q.size() == 1);
        }
};