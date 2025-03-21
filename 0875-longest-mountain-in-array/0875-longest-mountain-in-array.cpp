class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> up(n, 0), down(n, 0);
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1])
                up[i] = up[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1])
                down[i] = down[i + 1] + 1;
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (up[i] && down[i])
                maxi = max(maxi, up[i] + down[i] + 1);
        }
        return maxi;
    }
};