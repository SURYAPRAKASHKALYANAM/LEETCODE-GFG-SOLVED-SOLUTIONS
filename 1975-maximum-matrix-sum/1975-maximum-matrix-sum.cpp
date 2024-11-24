class Solution
{
    public:
        long long maxMatrixSum(vector<vector < int>> &matrix)
        {
            long long ans = 0;
            int n = matrix.size(), neg = 0, zero = 0;
            int minr = -1, minc = -1, min_val = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][j] < 0) neg++;
                    if (matrix[i][j] == 0) zero = 1;
                    if (min_val > abs(matrix[i][j])) min_val = min(min_val,abs(matrix[i][j]));
                    matrix[i][j] = abs(matrix[i][j]);
                }
            }
            for (int i = 0; i < n; i++) ans += accumulate(matrix[i].begin(), matrix[i].end(), 0);
            return zero ? ans : (neg &1 ? ans - 2 *min_val : ans);
        }
};