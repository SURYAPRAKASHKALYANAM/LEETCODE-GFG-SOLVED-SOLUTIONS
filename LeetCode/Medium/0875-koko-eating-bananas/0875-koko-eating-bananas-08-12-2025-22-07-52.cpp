class Solution {
public:
    long long helper(vector<int>& piles, long long div) {
        long long sum = 0LL;
        for (long long i : piles) {
            sum += (long long)((i / div) + (i % div ? 1 : 0));
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = *max_element(piles.begin(), piles.end());
        int mid, ans = end;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (helper(piles, mid) <= (long long)h) {
                ans = min(ans, mid);
                end = mid - 1;
            } else
                start = mid + 1;
        }
        return ans;
    }
};