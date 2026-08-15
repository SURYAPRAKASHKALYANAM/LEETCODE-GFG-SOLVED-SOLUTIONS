class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int len = strategy.size();
        vector<long long> prefSum(len), actSum(len);
        prefSum[0] = prices[0] * strategy[0] * 1LL;
        actSum[0] = prices[0];
        for (int i = 1; i < len; i++) {
            prefSum[i] = 1LL * (prices[i] * strategy[i]) + prefSum[i - 1];
            actSum[i] = 1LL * (prices[i]) + actSum[i - 1];
        }
        long long original = prefSum[len - 1];
        long long maxDif = 0, oldSum, newSum = 0;
        for (int i = k - 1; i < len; i++) {
            oldSum = prefSum[i] - ((i - k) >= 0 ? prefSum[i - k] : 0);
            newSum = actSum[i] - actSum[i - (k / 2)];
            maxDif = max(maxDif, newSum - oldSum);
        }
        return original + maxDif;
    }
};