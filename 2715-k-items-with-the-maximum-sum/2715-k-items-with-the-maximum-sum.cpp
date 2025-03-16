class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum = 0;
        if (k > 0)
            sum += min(k,numOnes), k = (k - numOnes);
        if (k > 0)
            k = (k - numZeros);
        if (k > 0)
            sum -= min(k,numNegOnes), k = (k - numNegOnes);
        return sum;
    }
};