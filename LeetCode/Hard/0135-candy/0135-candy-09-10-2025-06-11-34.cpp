class Solution {
public:
    int candy(vector<int>& ratings) {
        // /*
        // space complexity (2N) tc O(2N)
        int n = ratings.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;
            if (ratings[n - i - 1] > ratings[n - i])
                right[n - i - 1] = right[n - i] + 1;
        }
        int candies = 0;
        for (int i = 0; i < n; i++)
            candies += max(left[i], right[i]);
        return candies;
        // */
    }
};