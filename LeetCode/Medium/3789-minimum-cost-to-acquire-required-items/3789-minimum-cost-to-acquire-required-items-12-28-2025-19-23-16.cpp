class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long ans = 0;
        while (need1 || need2) {
            if (need1 && need2) {
                if ((cost1 + cost2) > costBoth) {
                    int mini = min(need1, need2);
                    ans += (1LL * costBoth * mini);
                    need1 -= mini;
                    need2 -= mini;
                } else {
                    ans += (1LL * cost1 * need1);
                    ans += (1LL * cost2 * need2);
                    need1 = need2 = 0;
                }
            } else if (need1) {
                if (cost1 > costBoth) {
                    ans += (1LL * costBoth * need1);
                    need1 = 0;
                } else {
                    ans += (1LL * cost1 * need1);
                    need1 = 0;
                }
            } else {
                if (cost2 > costBoth) {
                    ans += (1LL * costBoth * need2);
                    need2 = 0;
                } else {
                    ans += (1LL * cost2 * need2);
                    need2 = 0;
                }
            }
            cout << cost1 << " " << cost2 << " " << need1 << " " << need2
                 << endl;
        }
        return ans;
    }
};