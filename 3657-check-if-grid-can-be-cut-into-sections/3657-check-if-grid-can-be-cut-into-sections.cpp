class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> yaxis, xaxis;
        vector<vector<int>> ymerged, xmerged;
        for (auto i : rectangles) {
            yaxis.push_back({i[1], i[3]});
            xaxis.push_back({i[0], i[2]});
        }
        sort(xaxis.begin(), xaxis.end());
        for (auto i : xaxis) {
            if (xmerged.empty()) {
                xmerged.push_back(i);
            } else {
                if (xmerged.back()[1] > i[0]) {
                    xmerged.back()[1] = max(xmerged.back()[1], i[1]);
                } else
                    xmerged.push_back(i);
            }
        }
        if (xmerged.size() >= 3)
            return true;
        sort(yaxis.begin(), yaxis.end());
        for (auto i : yaxis) {
            if (ymerged.empty()) {
                ymerged.push_back(i);
            } else {
                if (ymerged.back()[1] > i[0]) {
                    ymerged.back()[1] = max(ymerged.back()[1], i[1]);
                } else
                    ymerged.push_back(i);
            }
        }
        return ymerged.size() >= 3;
    }
};