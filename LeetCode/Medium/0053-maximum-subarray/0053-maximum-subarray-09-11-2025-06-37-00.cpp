class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int currsum = 0;
        for (int i : nums) {
            currsum += i;
            max_sum = max(max_sum, currsum);
            if (currsum < 0)
                currsum = 0;
        }
        return max_sum;
    }
};