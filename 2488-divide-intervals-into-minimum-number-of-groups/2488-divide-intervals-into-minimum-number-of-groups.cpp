class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
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