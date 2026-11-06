class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [](const std::vector<int>& a, const std::vector<int>& b) {
                 if (a[1] != b[1]) {
                     return a[1] < b[1];
                 }
                 return a[0] < b[0];
             });
        logs.erase(std::unique(logs.begin(), logs.end()), logs.end());
        unordered_map<int, int> qAns;
        unordered_map<int, vector<int>> qIdx;
        int qLen = queries.size();
        vector<int> ans(qLen);
        for (int i = 0; i < qLen; i++) {
            if (qIdx.find(queries[i]) == qIdx.end())
                qIdx[queries[i]] = {i};
            else
                qIdx[queries[i]].emplace_back(i);
        }
        sort(queries.begin(), queries.end());
        auto [new_end, old_end] = ranges::unique(queries);
        queries.erase(new_end, old_end);
        unordered_map<int, int> seen;
        int l = 0, r = 0, uniqServ = 0;
        for (auto query : queries) {
            while (r < logs.size() && logs[r][1] <= query) {
                if (seen.find(logs[r][0]) == seen.end())
                    uniqServ++;
                seen[logs[r][0]]++;
                r++;
            }
            while (l <= r && l < logs.size() && logs[l][1] < query - x) {
                seen[logs[l][0]]--;
                if (seen[logs[l][0]] == 0) {
                    uniqServ--;
                    seen.erase(logs[l][0]);
                }
                l++;
            }
            qAns[query] = n - uniqServ;
        }
        for (auto idxs : qIdx) {
            for (auto idx : idxs.second) {
                ans[idx] = qAns[idxs.first];
            }
        }
        return ans;
    }
};