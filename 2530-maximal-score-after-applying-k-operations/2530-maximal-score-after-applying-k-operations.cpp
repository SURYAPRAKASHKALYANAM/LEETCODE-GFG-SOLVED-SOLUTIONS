class Solution
{
    public:
        long long maxKelements(vector<int> &nums, int k)
        {
            long long score = 0, r, v;
            priority_queue<int> q(nums.begin(), nums.end());
            while (k--)
            {
                r = q.top();
                score += r;
                q.pop();
                v = (r % 3) ? (r / 3) + 1 : r / 3;
                q.push(v);
            }
            return score;
        }
};