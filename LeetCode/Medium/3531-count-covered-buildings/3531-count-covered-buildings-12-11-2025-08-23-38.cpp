class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int, int>> xMap, yMap;
        for (auto& point : buildings) {
            if (xMap[point[0]].first != 0) {
                xMap[point[0]].first = min(xMap[point[0]].first, point[1]);
                xMap[point[0]].second = max(xMap[point[0]].second, point[1]);
            } else
                xMap[point[0]] = {point[1], point[1]};
            if (yMap[point[1]].first != 0) {
                yMap[point[1]].first = min(yMap[point[1]].first, point[0]);
                yMap[point[1]].second = max(yMap[point[1]].second, point[0]);
            } else {
                yMap[point[1]] = {point[0], point[0]};
            }
        }
        int ans = 0;
        for (auto& point : buildings) {
            if (xMap[point[0]].first < point[1] &&
                xMap[point[0]].second > point[1] &&
                yMap[point[1]].first < point[0] &&
                yMap[point[1]].second > point[0])
                ans++;
        }
        return ans;
    }
};