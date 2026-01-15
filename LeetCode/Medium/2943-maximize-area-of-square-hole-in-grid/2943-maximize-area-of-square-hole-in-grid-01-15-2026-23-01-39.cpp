class Solution {
public:
    int find(vector<int>& bars) {
        int prev = -1, start;
        int max_len = 0;
        for (int& bar : bars) {
            if (prev == bar - 1) {
                prev = bar;
                max_len = max(bar - start, max_len);
            } else {
                start = prev = bar;
            }
        }
        return max_len;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int len = min(find(hBars), find(vBars)) + 2;
        return len * len;
    }
};