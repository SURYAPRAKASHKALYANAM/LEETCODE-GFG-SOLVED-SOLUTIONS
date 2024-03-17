class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.emplace_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> sol;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (sol.empty() || intervals[i][0] > sol.back()[1]) sol.emplace_back(intervals[i]);
            else
            {
                sol.back()[1] = max(sol.back()[1], intervals[i][1]);
            }
        }
        return sol;
    }
};