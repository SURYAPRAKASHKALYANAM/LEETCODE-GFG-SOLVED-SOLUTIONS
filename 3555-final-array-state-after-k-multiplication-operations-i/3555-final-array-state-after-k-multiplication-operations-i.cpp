class Solution
{
    public:
        vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
        {
            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> q;
            for (int i = 0; i < nums.size(); i++) q.push({ nums[i],i });
            while (k--)
            {
                auto i = q.top();
                q.pop();
                q.push({ i.first *multiplier,i.second });
            }
            while (!q.empty())
            {
                auto i = q.top();
                q.pop();
                nums[i.second] = i.first;
            }
            return nums;
        }
};