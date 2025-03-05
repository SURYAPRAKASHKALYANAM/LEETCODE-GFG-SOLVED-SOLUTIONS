/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> m;
        vector<vector<int>> verticalOrder;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            root = it.first;
            int x = it.second.first, y = it.second.second;
            m[x][y].insert(root->val);
            if (root->left) {
                q.push({root->left, {x - 1, y + 1}});
            }
            if (root->right) {
                q.push({root->right, {x + 1, y + 1}});
            }
        }
        for (auto axis : m) {
            vector<int> axisele;
            for (auto level : axis.second)
                axisele.insert(axisele.end(), level.second.begin(),
                               level.second.end());
            verticalOrder.push_back(axisele);
        }
        return verticalOrder;
    }
};