class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int wind = k - 1;
        int leftSum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int max_sum = leftSum;
        while (wind >= 0) {
            leftSum -= cardPoints[wind];
            leftSum += cardPoints[n - (k - wind)];
            wind--;
            max_sum = max(max_sum, leftSum);
        }
        return max_sum;
    }
};