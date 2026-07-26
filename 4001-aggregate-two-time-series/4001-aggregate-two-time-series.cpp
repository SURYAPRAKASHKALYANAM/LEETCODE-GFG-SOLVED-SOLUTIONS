class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int p1 = 0, p2 = 0;
        int len1 = series1.size(), len2 = series2.size();
        while (p1 < len1 && p2 < len2) {
            if (series1[p1][0] == series2[p2][0]) {
                ans.push_back(
                    {series1[p1][0], series1[p1][1] + series2[p2][1]});
                p1++;
                p2++;
            } else if (series1[p1][0] < series2[p2][0]) {
                int cnt = series1[p1][1] + series2[p2][1];
                ans.push_back({series1[p1][0], cnt});
                p1++;
            } else {
                int cnt = series2[p2][1] + series1[p1][1];
                ans.push_back({series2[p2][0], cnt});
                p2++;
            }
        }
        while (p1 < len1)
            ans.push_back(series1[p1++]);
        while (p2 < len2)
            ans.push_back(series2[p2++]);
        return ans;
    }
};