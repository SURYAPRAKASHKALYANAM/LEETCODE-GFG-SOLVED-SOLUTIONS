class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int sqrsCnt = 0;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    if (i - 1 >= 0 && j - 1 >= 0) {
                        int minLen = min({matrix[i - 1][j - 1],
                                          matrix[i][j - 1], matrix[i - 1][j]}) +1;
                        matrix[i][j] = minLen;
                        sqrsCnt += (minLen);

                    } else
                        sqrsCnt++;
                }
            }
        }
        return sqrsCnt;
    }
};