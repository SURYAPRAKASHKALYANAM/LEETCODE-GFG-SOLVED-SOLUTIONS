class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // optimal
        int freq[1000002] = {0};
        for (int i = 0, n = intervals.size(); i < n; ++i) {
            ++freq[intervals[i][0]];
            --freq[intervals[i][1] + 1];
        }
        int curr = 0, res = 1;
        for (int i = 0; i < 1000002; ++i) {
            curr += freq[i];
            res = max(res, curr);
        }
        return res;
        // extra space
        vector<int> start, ends;
        for (auto i : intervals) {
            start.emplace_back(i[0]);
            ends.emplace_back(i[1]);
        }
        int len = start.size();
        sort(start.begin(), start.end());
        sort(ends.begin(), ends.end());
        int i = 0, j = 0;
        int cnt = 0, minGrp = 0;
        while (i < len) {
            if (start[i] <= ends[j]) {
                i++;
                minGrp = max(++cnt, minGrp);
            } else {
                j++;
                cnt--;
            }
        }
        return minGrp;
    }
};