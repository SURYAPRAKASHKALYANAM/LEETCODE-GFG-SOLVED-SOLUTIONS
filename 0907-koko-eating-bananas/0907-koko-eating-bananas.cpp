class Solution {
public:
    long long helper(vector<int>& piles, long long k, int lim) {
        long long time = 0LL;
        for (long long i : piles) {
            // time += (long long)((i / k) + (i % k ? 1 : 0));
            time += ((long long)i + k - 1) / k;
            if (time > lim)
                return 2;
        }
        return (time == lim ? 1 : 0);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = *max_element(piles.begin(), piles.end());
        int mid, ans = end;
        while (start <= end) {
            mid = start + (end - start) / 2;
            int val = helper(piles, mid, h);
            if (val <= 1) {
                ans = min(ans, mid);
                end = mid - 1;
            } else if (val == 2)
                start = mid + 1;
        }
        return ans;
    }
};