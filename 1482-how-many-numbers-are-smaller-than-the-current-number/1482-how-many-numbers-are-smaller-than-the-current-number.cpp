class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> sorted_positions;
        vector<int> sortednums(nums), ans(len);
        sort(sortednums.begin(), sortednums.end());
        for (int i = 0; i < len; i++) {
            if (sorted_positions.find(sortednums[i]) ==
                sorted_positions.end()) {
                sorted_positions[sortednums[i]] = i;
            }
        }
        for (int i = 0; i < len; i++) {
            ans[i] = sorted_positions[nums[i]];
        }
        return ans;
    }
};