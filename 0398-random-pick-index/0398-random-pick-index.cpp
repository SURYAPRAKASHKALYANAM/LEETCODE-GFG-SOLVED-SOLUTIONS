class Solution {
public:
    unordered_map<int, multiset<pair<int, int>>> pos;
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].insert({0, i});
        }
    }

    int pick(int target) {
        auto targetIdx = pos[target].begin();
        int idx = targetIdx->second;
        pos[target].insert({(targetIdx->first) + 1, targetIdx->second});
        pos[target].erase(targetIdx);
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */