class Solution {
public:
    // void generate(int pos, vector<int>& nums, vector<int>& sub,
    //               vector<vector<int>>& ans, int len) {
    //     if (pos == len) {
    //         ans.emplace_back(sub);
    //         return;
    //     }
    //     sub.emplace_back(nums[pos]);
    //     generate(pos + 1, nums, sub, ans, len);
    //     sub.pop_back();
    //     generate(pos + 1, nums, sub, ans, len);
    // }
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     // your code goes here
    //     vector<vector<int>> ans;
    //     vector<int> sub;
    //     generate(0, nums, sub, ans, nums.size());
    //     return ans;
    // }

    vector<vector<int>> subsets(vector<int>& nums) {
        // BIT MANIPULATION
        int len = nums.size();
        int n = (1 << len);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            vector<int> sub;
            for (int j = 0; j < len; j++) {
                if (i & (1 << j))
                    sub.emplace_back(nums[j]);
            }
            ans.emplace_back(sub);
        }
        return ans;
    }
};