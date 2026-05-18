class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> idxs;
        int len = arr.size();
        for (int i = 0; i < len; i++) {
            idxs[arr[i]].emplace_back(i);
        }
        unordered_set<int> vis;
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis.insert(0);
        while (!q.empty()) {
            auto [pos, steps] = q.front();
            q.pop();
            if (pos == len - 1)
                return steps;

            // forward
            if (pos + 1 < len && vis.count(pos + 1) == 0) {
                q.push({pos + 1, steps + 1});
                vis.insert(pos + 1);
            }

            // backward
            if (pos - 1 >= 0 && vis.count(pos - 1) == 0) {
                q.push({pos - 1, steps + 1});
                vis.insert(pos - 1);
            }

            for (int next : idxs[arr[pos]]) {
                if (!vis.count(next)) {
                    vis.insert(next);
                    q.push({next, steps + 1});
                }
            }
            idxs[arr[pos]].clear(); // gold
        }
        return -1;
    }
};