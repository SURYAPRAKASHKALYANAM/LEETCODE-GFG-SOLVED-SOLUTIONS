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
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.second.first, y = it.second.second;
            nodes[x][y].insert(it.first->val);
            if (it.first->left) {
                q.push({it.first->left, {x - 1, y + 1}});
            }
            if (it.first->right) {
                q.push({it.first->right, {x + 1, y + 1}});
            }
        }
        for (auto [xInd, order] : nodes) {
            vector<int> temp;
            for (auto [yInd, suborder] : order) {
                temp.insert(temp.end(), suborder.begin(), suborder.end());
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};