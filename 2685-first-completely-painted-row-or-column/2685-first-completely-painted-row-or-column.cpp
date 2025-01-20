class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, int> row, col;
        unordered_map<int, pair<int, int>> index;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                index[mat[i][j]] = {i, j};
        for (auto i = 0; i < arr.size(); i++) {
            int r = index[arr[i]].first, c = index[arr[i]].second;
            if ((++row[r] == n) || (++col[c] == m))
                return i;
        }
        return -1;
    }
};