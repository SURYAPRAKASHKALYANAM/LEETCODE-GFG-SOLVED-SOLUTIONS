class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ind(n + 1, 0);
        for (auto i : queries) {
            ind[i[0]] -= 1;
            ind[i[1] + 1] += 1;
        }
        for (int i = 0; i < n; i++) {
            if (i > 0)
                ind[i] += ind[i - 1];
            nums[i] += ind[i];
            if (nums[i] > 0)
                return false;
        }
        return true;
    }
};