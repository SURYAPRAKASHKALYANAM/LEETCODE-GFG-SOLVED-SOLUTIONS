class Solution {
public:
    bool isEnoughStrength(long long curr, vector<int>& monsters,
                          vector<long long>& bonuses) {
        for (int i = 0; i < monsters.size(); i++) {
            if (curr + bonuses[i] < 1LL * monsters[i])
                return false;
            curr -= monsters[i];
            if (curr < 0)
                curr = 0;
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monsters,
                                 vector<vector<int>>& boosts) {
        int len = monsters.size();
        vector<long long> bonuses(len + 1, 0LL);
        for (auto& boost : boosts) {
            int l = boost[0], r = boost[1];
            long long v = boost[2];
            bonuses[l] += v;
            bonuses[r + 1] -= v;
        }
        for (int i = 1; i <= len; i++) {
            bonuses[i] += bonuses[i - 1];
        }
        long long start = 0LL,end = accumulate(monsters.begin(), monsters.end(), 0LL), mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (isEnoughStrength(mid, monsters, bonuses)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};