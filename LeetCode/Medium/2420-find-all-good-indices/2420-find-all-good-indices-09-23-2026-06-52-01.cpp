class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> increasing(n, 1), decreasing(n, 1), ans;
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i - 1])
                increasing[i] = increasing[i - 1] + 1;
            if (nums[i] <= nums[i - 1])
                decreasing[i] = decreasing[i - 1] + 1;
        }
        for (int i = k; i + k < n; i++) {
            if ((decreasing[i - 1] - decreasing[i - k] + 1) == k &&
                (increasing[i + k] - increasing[i + 1] + 1) == k)
                ans.emplace_back(i);
        }
        return ans;
    }
};