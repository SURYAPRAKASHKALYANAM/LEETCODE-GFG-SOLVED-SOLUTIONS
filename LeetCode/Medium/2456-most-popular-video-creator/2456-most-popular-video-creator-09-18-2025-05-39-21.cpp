class Compare {
public:
    bool operator()(pair<int, string> p1, pair<int, string> p2) const {
        if (p1.first == p2.first)
            return p1.second > p2.second;
        return p1.first < p2.first;
    }
};
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators,
                                              vector<string>& ids,
                                              vector<int>& views) {
        unordered_map<string, long long> viewsMap;
        unordered_map<string, set<pair<int, string>, Compare>> idsMap;
        vector<vector<string>> ans;
        int len = ids.size();
        long long max_views = -1L;
        for (int i = 0; i < len; i++) {
            viewsMap[creators[i]] += views[i];
            idsMap[creators[i]].insert({views[i], ids[i]});
            max_views = max(max_views, viewsMap[creators[i]]);
        }
        for (auto creator : viewsMap) {
            if (creator.second == max_views) {
                ans.push_back(
                    {creator.first, (idsMap[creator.first].rbegin())->second});
            }
        }
        return ans;
    }
};