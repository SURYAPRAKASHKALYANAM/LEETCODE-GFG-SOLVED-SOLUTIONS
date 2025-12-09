class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> totCnt, cntSoFar;
        for (auto& i : nums)
            totCnt[i]++;
        int spcl = 0, mod = 1e9 + 7;
        for (auto& i : nums) {
            long rightCnt = totCnt[i * 2] - cntSoFar[i * 2];
            if (rightCnt > 0 && cntSoFar[i * 2]) {
                rightCnt = rightCnt - (i * 2 == i ? 1 : 0);
                spcl = (spcl + (cntSoFar[i * 2] * (rightCnt)) % mod) % mod;
            }
            cntSoFar[i]++;
        }
        return spcl;
    }
};