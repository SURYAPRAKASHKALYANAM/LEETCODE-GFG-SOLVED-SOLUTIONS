/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        Node* newNode = new Node(node->val);
        vector<Node*> nodeof(101);
        vector<int> vis(101);
        queue<Node*> q;
        nodeof[node->val] = newNode;
        q.push(node);
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            if (vis[it->val])
                continue;
            vis[it->val] = 1;
            for (auto neigh : it->neighbors) {
                if (nodeof[neigh->val]) {
                    nodeof[neigh->val]->neighbors.emplace_back(nodeof[it->val]);
                } else {
                    nodeof[neigh->val] = new Node(neigh->val);
                    nodeof[neigh->val]->neighbors.emplace_back(nodeof[it->val]);
                }
                q.push(neigh);
            }
        }

        return newNode;
    }
};