class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points,vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> ans(q, 0);
        for (auto i = 0; i < q; i++) {
            int x = queries[i][0], y = queries[i][1];
            double r = queries[i][2];
            for (auto point : points) {
                if (((double)sqrt(pow(x - point[0], 2) + pow(y - point[1], 2))) <= r)
                    ans[i]++;
            }
        }
        return ans;
    }
};