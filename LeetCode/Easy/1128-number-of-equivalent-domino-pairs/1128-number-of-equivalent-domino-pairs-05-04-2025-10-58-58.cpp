class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> seen;
        int cnt = 0;
        for (auto i : dominoes) {
            int digit = max(i[0], i[1]) * 10 + min(i[0], i[1]);
            cnt += seen[digit];
            seen[digit]++;
        }
        return cnt;
    }
};