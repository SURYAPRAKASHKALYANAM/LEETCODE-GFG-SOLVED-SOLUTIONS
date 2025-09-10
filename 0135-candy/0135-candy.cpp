class Solution {
public:
    int candy(vector<int>& ratings) {

        // space complexity (N) tc O(2N)

        int n = ratings.size();
        vector<int> left(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        int curr = 1, right = 1, sum = max(left[n - 1], curr);
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                curr = right + 1;
            } else
                curr = 1;
            right = curr;
            sum += max(curr, left[i]);
        }
        return sum;

        /*
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
         */
    }
};