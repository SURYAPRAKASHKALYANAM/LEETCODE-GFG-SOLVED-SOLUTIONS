class Solution {
public:
    int helper(int day, vector<int>& bloomDay, int window, int len) {
        int possible = 0;
        int start = 0, cnt = 0;
        while (start < len) {
            if (bloomDay[start] <= day) {
                cnt++;
            } else {
                possible += (cnt / window);
                cnt = 0;
            }
            start++;
        }
        possible += (cnt / window);
        return possible;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 1, end = *max_element(bloomDay.begin(), bloomDay.end());
        int mid, ans = INT_MAX, n = bloomDay.size();
        while (start <= end) {
            mid = start + (end - start) / 2;
            int val = helper(mid, bloomDay, k, n);
            if (val >= m) {
                ans = min(ans, mid);
                end = mid - 1;
            } else
                start = mid + 1;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};