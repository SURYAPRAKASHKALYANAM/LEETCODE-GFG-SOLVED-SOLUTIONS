class Solution {
public:
    long long computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                          int bx2, int by2) {
        if ((bx2 <= ax1 || bx1 >= ax2) || (by1 >= ay2 || by2 <= ay1)) {
            return 0;
        }
        int l = abs(max(ax1, bx1) - min(ax2, bx2));
        int w = abs(max(ay1, by1) - min(ay2, by2));
        long long s = min(l, w);
        return (long long)s * s;
    }
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        long long ans = 0;
        int len = bottomLeft.size();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                ans = max(ans, computeArea(bottomLeft[i][0], bottomLeft[i][1],
                                           topRight[i][0], topRight[i][1],
                                           bottomLeft[j][0], bottomLeft[j][1],
                                           topRight[j][0], topRight[j][1]));
            }
        }
        return ans;
    }
};