class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int start = 0, end = m - 1, mid;
        while (start <= end) {
            mid = (start + end) / 2;
            int maxCol = max_element(mat[mid].begin(), mat[mid].end()) -
                         mat[mid].begin();
            int top = (mid - 1) >= 0 ? mat[mid - 1][maxCol] : -1;
            int bottom = (mid + 1) < m ? mat[mid + 1][maxCol] : -1;
            int val = mat[mid][maxCol];
            if (top < val && val > bottom)
                return {mid, maxCol};
            else if (top > val)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return {-1, -1};
    }
};