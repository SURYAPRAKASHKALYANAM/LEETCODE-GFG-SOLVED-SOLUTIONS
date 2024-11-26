class Solution
{
    public:
        int findChampion(int n, vector<vector < int>> &edges)
        {
            unordered_map<int, int> m;
            for (auto i: edges) m[i[1]]++;
            int champ = -1;
            for (int i = 0; i < n; i++)
            {
                if (!m[i])
                {
                    if (champ == -1) champ = i;
                    else return -1;
                }
            }
            return champ;
        }
};