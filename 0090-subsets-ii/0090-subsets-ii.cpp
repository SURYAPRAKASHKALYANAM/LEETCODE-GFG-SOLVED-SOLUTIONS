class Solution {
public:
    void generate(int pos, vector<int>& nums, vector<int>& sub,
                  set<vector<int>>& ans, int len) {
        if (pos == len) {
            ans.insert(sub);
            return;
        }
        sub.emplace_back(nums[pos]);
        generate(pos + 1, nums, sub, ans, len);
        sub.pop_back();
        generate(pos + 1, nums, sub, ans, len);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // your code goes here
        set<vector<int>> ans;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        generate(0, nums, sub, ans, nums.size());
        vector<vector<int>> finalAns(ans.begin(), ans.end());
        return finalAns;
    }
};