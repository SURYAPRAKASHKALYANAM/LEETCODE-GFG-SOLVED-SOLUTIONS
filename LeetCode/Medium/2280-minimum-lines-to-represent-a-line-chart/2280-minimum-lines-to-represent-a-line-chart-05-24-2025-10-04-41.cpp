class Solution {
public:
    int minimumLines(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        long double slope, prevSlope = INT_MAX;
        int linesCount = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            if (points[i + 1][0] - points[i][0] == 0)
                slope = INT_MAX;
            else
                slope = (long double)(points[i + 1][1] - points[i][1]) /
                    (points[i + 1][0] - points[i][0]);
            if (slope != prevSlope) {
                linesCount++;
                prevSlope = slope;
            }
        }
        return linesCount;
    }
};