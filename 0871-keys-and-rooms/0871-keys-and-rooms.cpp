class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(), 0);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            if (vis[it])
                continue;
            vis[it] = 1;
            for (auto neigh : rooms[it]) {
                if (!vis[neigh]) {
                    q.push(neigh);
                }
            }
        }
        return find(begin(vis), end(vis), 0) == end(vis);
    }
};