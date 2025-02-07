class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> colorcounts,ballColor;
        int diff_color = 0;
        for (int i = 0; i < n; i++) {
            int x = queries[i][0], y = queries[i][1];
            if (!ballColor[x]) {
                if (!colorcounts[y]) {
                    diff_color++;
                }
                ballColor[x] = y;
                colorcounts[y]++;
            } else {
                if (ballColor[x] != y) {
                    colorcounts[ballColor[x]]--;
                    if (!colorcounts[ballColor[x]])
                        diff_color--;
                    if (!colorcounts[y]) {
                        diff_color++;
                    }
                    ballColor[x] = y;
                    colorcounts[y]++;
                }
            }
            result[i] = diff_color;
        }
        return result;
    }
};