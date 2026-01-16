class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
        hFences.emplace_back(1);
        vFences.emplace_back(1);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        hFences.emplace_back(m);
        vFences.emplace_back(n);
        int hLen = hFences.size(), vLen = vFences.size();
        unordered_set<long long> possibleLen;
        long long max_area = 0, mod = 1e9 + 7;
        for (int i = 0; i < hLen; i++) {
            for (int j = i; j < hLen; j++) {
                long long len;
                if (i == j)
                    len = hFences[i] - 1;
                else
                    len = hFences[j] - hFences[i];
                possibleLen.insert(len);
            }
        }
        for (int i = 0; i < vLen; i++) {
            for (int j = i; j < vLen; j++) {
                long long len;
                if (i == j)
                    len = vFences[i] - 1;
                else
                    len = vFences[j] - vFences[i];
                if (possibleLen.find(len) != possibleLen.end()) {
                    max_area = max(len * len, max_area);
                }
            }
        }

        return max_area == 0 ? -1 : (max_area % mod);
    }
};