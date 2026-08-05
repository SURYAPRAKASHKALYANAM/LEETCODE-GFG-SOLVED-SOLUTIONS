class Solution {
public:
    bool connectedToSpam(int node, vector<int> adj[],
                         unordered_set<int>& spam,unordered_set<int>& vis) {
        if(spam.find(node)!=spam.end()) return true;
        if(vis.find(node)!=vis.end()) return false;
        vis.insert(node);
        for(auto next:adj[node]){
            if(connectedToSpam(next,adj,spam,vis)) return true;
        }
        return false;
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<int> adj[n];
        for (auto invokes : invocations) {
            adj[invokes[0]].push_back(invokes[1]);
        }
        unordered_set<int> spam, vis;
        queue<int> q;
        q.push(k);
        vis.insert(k);
        while (!q.empty()) {
            int method = q.front();
            q.pop();
            spam.insert(method);
            for (int next : adj[method]) {
                if (vis.find(next) == vis.end()) {
                    vis.insert(next);
                    q.push(next);
                }
            }
        }
        vector<int> ans;
        vis.clear();
        for (int i = 0; i < n; i++) {
            if (spam.find(i) == spam.end()) {
                if (connectedToSpam(i, adj, spam,vis)) {
                    ans.clear();
                    for(int i=0;i<n;i++) ans.push_back(i);
                    break;
                } else {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};