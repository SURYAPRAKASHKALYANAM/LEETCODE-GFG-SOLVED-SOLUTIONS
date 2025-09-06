class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int len = pairs.size();
        sort(pairs.begin(), pairs.end(),
             [&](vector<int>& p1, vector<int>& p2) { return p1[1] < p2[1]; });
        int chainLen = 1;
        int lastEnd = pairs[0][1];
        for (int i = 1; i < len; i++) {
            if (pairs[i][0] > lastEnd) {
                lastEnd = pairs[i][1];
                chainLen++;
            }
        }
        return chainLen;
    }
};