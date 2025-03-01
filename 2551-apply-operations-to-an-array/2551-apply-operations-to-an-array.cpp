class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int zero = 0, len = nums.size();
        vector<int> dup;
        for (int i = 0; i < len; i++) {
            if (!nums[i])
                zero++;
            else if (i + 1 < len && nums[i] == nums[i + 1]) {
                dup.emplace_back(nums[i] * 2);
                zero++;
                i++;
            } else
                dup.emplace_back(nums[i]);
        }
        while (zero-- > 0) {
            dup.emplace_back(0);
        }
        return dup;
    }
};