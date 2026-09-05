class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> maxTill(len), minEnd(len);
        maxTill[0] = nums[0], minEnd[len - 1] = nums[len - 1];
        for (int i = 1; i < len; i++) {
            maxTill[i] = max(maxTill[i - 1], nums[i]);
            minEnd[len - i - 1] = min(minEnd[len - i], nums[len - i - 1]);
        }

        for (int i = 0; i < len; i++) {
            if (maxTill[i] - minEnd[i] <= k)
                return i;
        }

        return -1;
    }
};