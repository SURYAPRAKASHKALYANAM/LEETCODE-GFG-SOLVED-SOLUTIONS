class Solution {
   public:
    void generate(vector<vector<int>>& ans, vector<int>& nums, int pos,
                  vector<int>& sub, int len) {
        if (pos == len) {
            ans.emplace_back(sub);
            return;
        }
        sub.emplace_back(nums[pos]);
        generate(ans, nums, pos + 1, sub, len);
        sub.pop_back();
        int nextPos = pos;
        while (nextPos + 1 < len && nums[nextPos] == nums[nextPos + 1])
            nextPos++;
        generate(ans, nums, nextPos + 1, sub, len);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // your code goes here
        vector<vector<int>> ans;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        generate(ans, nums, 0, sub, nums.size());
        return ans;
    }
};