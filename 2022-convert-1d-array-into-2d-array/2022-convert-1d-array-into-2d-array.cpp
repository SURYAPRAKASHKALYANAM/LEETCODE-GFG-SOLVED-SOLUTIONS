class Solution
{
    public:
        vector<vector < int>> construct2DArray(vector<int> &original, int m, int n)
        {
            if (original.size() != m *n) return {};
            vector<vector < int>> sol(m, vector<int> (n));
            for (int i = 0; i < original.size(); i++)
            {
                int r = i / n, c = (i % n);
                sol[r][c] = original[i];
            }
            return sol;
        }
};