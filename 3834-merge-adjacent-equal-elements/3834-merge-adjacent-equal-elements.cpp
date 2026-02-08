class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (ans.empty())
                ans.push_back(nums[i] * 1LL);
            else {
                long long curr = nums[i];
                while ((!ans.empty()) && (ans.back() == curr)) {
                    curr += ans.back();
                    ans.pop_back();
                }
                ans.push_back(curr);
            }
        }
        return ans;
    }
};