class Solution
{
    public:
        vector<string> findRelativeRanks(vector<int> &score)
        {
            vector<string> ans(score.size(), "");
            priority_queue<pair<int, int>> q;
            for (int i = 0; i < score.size(); i++) q.push({ score[i],i });
            int l = 0;
            while (!q.empty())
            {
                if (l == 0) ans[q.top().second] += "Gold Medal";
                else if (l == 1) ans[q.top().second] += "Silver Medal";
                else if (l == 2) ans[q.top().second] += "Bronze Medal";
                else ans[q.top().second] += to_string(l + 1);
                l++;
                q.pop();
            }
            return ans;
        }
};