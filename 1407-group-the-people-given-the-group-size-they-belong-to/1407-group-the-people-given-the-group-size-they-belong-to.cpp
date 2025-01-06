class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> m;
        // for (auto i = 0; i < groupSizes.size(); i++)
        //     m[groupSizes[i]].emplace_back(i);
        // for (auto i : m) {
        //     vector<int> sub;
        //     for (int curr = 0; curr < i.second.size(); curr++) {
        //         sub.emplace_back(i.second[curr]);
        //         if ((curr + 1) % i.first == 0) {
        //             ans.emplace_back(sub);
        //             sub.clear();
        //         }
        //     }
        // }
        // OPTIMAL
        for (int i = 0; i < groupSizes.size(); i++) {
            int len = groupSizes[i];
            m[len].emplace_back(i);
            if (m[len].size() == len) {
                ans.emplace_back(m[len]);
                m[len] = {};
            }
        }
        return ans;
    }
};