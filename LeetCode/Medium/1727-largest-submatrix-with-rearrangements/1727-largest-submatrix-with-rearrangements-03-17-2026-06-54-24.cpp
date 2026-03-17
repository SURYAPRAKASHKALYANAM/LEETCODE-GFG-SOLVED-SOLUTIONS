class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < m; i++) {
                if (matrix[i][j] == 0)
                    sum = 0;
                else {
                    sum++;
                    matrix[i][j] = sum;
                }
            }
        }
        int max_area = 0;
        for (int i = 0; i < m; i++) {
            sort(matrix[i].begin(), matrix[i].end(), greater<>());
            int minW = INT_MAX;
            for (int j = 0; j < n; j++) {
                minW = min(minW, matrix[i][j]);
                max_area = max(max_area, (j + 1) * minW);
            }
        }
        return max_area;
    }
};