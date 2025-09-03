class Solution {
public:
    void generate(int pos, vector<int>& nums, vector<int>& sub,
                  vector<vector<int>>& ans, int len) {
        if (pos == len) {
            ans.emplace_back(sub);
            return;
        }
        sub.emplace_back(nums[pos]);
        generate(pos + 1, nums, sub, ans, len);
        sub.pop_back();
        generate(pos + 1, nums, sub, ans, len);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // your code goes here
        vector<vector<int>> ans;
        vector<int> sub;
        generate(0, nums, sub, ans, nums.size());
        return ans;
    }
};