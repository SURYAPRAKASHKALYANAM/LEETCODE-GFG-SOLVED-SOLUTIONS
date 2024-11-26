class Solution
{
    public:
        int findChampion(vector<vector < int>> &grid)
        {
            int n = grid.size();
            vector<int> indegree(n);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i != j && grid[i][j]) indegree[j]++;
                    else indegree[i]++;
                }
            }
            int champ = -1, min = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                if (indegree[i] < min)
                {
                    champ = i;
                    min = indegree[i];
                }
            }
            return champ;
        }
};