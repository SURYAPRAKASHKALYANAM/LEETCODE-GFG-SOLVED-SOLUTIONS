class Solution
{
    public:
        long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector< int > &cost)
        {
            long long ans = 0;
            int n = original.size();
            vector<vector < int>> matrix(26, vector<int> (26, 1e9));
            for (int i = 0; i < n; i++)
            {
                matrix[original[i] - 'a'][changed[i] - 'a'] = min(matrix[original[i] - 'a'][changed[i] - 'a'], cost[i]);
            }
            for (int via = 0; via < 26; via++)
            {
                matrix[via][via] = 0;
                for (int i = 0; i < 26; i++)
                {
                    for (int j = 0; j < 26; j++) matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
            for (int i = 0; i < source.size(); i++)
            {
                if (matrix[source[i] - 'a'][target[i] - 'a'] == 1e9) return -1;
                ans += matrix[source[i] - 'a'][target[i] - 'a'];
            }
            return ans;
        }
};