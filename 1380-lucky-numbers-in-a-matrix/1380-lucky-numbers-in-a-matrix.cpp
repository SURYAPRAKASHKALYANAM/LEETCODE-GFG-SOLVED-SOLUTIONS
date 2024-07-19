class Solution
{
    public:
        vector<int> luckyNumbers(vector<vector < int>> &matrix)
        {
            vector<int> max_col(matrix[0].size(), 0), min_row(matrix.size(), INT_MAX), ans;
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    min_row[i] = min(min_row[i], matrix[i][j]);
                }
            }
            for (int j = 0; j < matrix[0].size(); j++)
            {
                for (int i = 0; i < matrix.size(); i++)
                {
                    max_col[j] = max(max_col[j], matrix[i][j]);
                }
            }
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    if (matrix[i][j] == min_row[i] && matrix[i][j] == max_col[j])
                        ans.emplace_back(matrix[i][j]);
                }
            }
            return ans;
        }
};