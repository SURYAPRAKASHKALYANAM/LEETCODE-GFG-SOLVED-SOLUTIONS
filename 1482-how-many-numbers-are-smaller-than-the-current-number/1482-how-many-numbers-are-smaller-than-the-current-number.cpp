class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> counts(102, 0);
        for (auto i : nums)
            counts[i + 1] += 1;
        for (int i = 1; i < 102; i++)
            counts[i] += counts[i - 1];
        vector<int> ans;
        for (auto i : nums)
            ans.emplace_back(counts[i]);
        return ans;
    }
};