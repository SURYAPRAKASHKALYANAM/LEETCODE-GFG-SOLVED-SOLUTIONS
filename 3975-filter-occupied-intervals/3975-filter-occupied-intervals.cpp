class Solution {
public:
    vector<vector<int>>
    filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                            int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<vector<int>> intervals;
        for (auto interval : occupiedIntervals) {
            if (intervals.empty())
                intervals.push_back(interval);
            else if (intervals.back()[1] >= interval[0] ||
                     intervals.back()[1] + 1 == interval[0]) {
                intervals.back()[1] = max(intervals.back()[1], interval[1]);
            } else {
                intervals.push_back(interval);
            }
        }
        vector<vector<int>> ans;
        for (auto interval : intervals) {
            cout << interval[0] << " " << interval[1] << "\n";
            if (interval[1] <= freeEnd && interval[0] >= freeStart)
                continue;
            else if (interval[1] >= freeStart && interval[0] <= freeStart) {
                if (interval[0] != freeStart)
                    ans.push_back({interval[0], freeStart - 1});
                if (freeEnd + 1 <= interval[1]) {
                    ans.push_back({freeEnd + 1, interval[1]});
                }
            } else if (interval[0] <= freeEnd && interval[1] >= freeEnd) {
                if (freeStart - 1 >= interval[0]) {
                    ans.push_back({interval[0], freeStart - 1});
                }
                if (interval[1] != freeEnd)
                    ans.push_back({freeEnd + 1, interval[1]});
            } else {
                ans.push_back(interval);
            }
        }
        return ans;
    }
};