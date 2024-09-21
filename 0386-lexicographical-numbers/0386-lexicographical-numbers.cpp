class Solution
{
    public:
        void dfs(vector<int> &ans, int curr, int n)
        {
            if (curr > n) return;
            for (int i = 0; i <= 9; i++)
            {
                if ((curr + i) > 0 && (curr + i) <= n)
                {
                    ans.emplace_back(curr + i);
                    dfs(ans, (curr + i) *10, n);
                }
            }
        }
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        dfs(ans, 0, n);
        return ans;
    }
};