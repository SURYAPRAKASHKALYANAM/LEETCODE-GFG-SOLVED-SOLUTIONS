/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void help(unordered_map<TreeNode*, pair<TreeNode*, int>> &parent, TreeNode *root)
        {
            if (!root) return;
            if (root->left) parent[root->left] = {root,1};
            help(parent, root->left);
            if (root->right) parent[root->right] = {root,0};
            help(parent, root->right);
        }
    vector<TreeNode*> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        unordered_map<TreeNode*, pair<TreeNode*, int>> parent;
        vector<TreeNode*> ans;
        help(parent, root);
        unordered_map<int, bool> remove;
        for (auto i: to_delete) remove[i] = 1;
        for (auto node: parent)
        {
            if (remove[node.first->val])
            {
                if (node.second.second) parent[node.first].first->left = NULL;
                else parent[node.first].first->right = NULL;
                if (node.first->left && !remove[node.first->left->val]) ans.emplace_back(node.first->left);
                if (node.first->right && !remove[node.first->right->val]) ans.emplace_back(node.first->right);
            }
        }
        if (!remove[root->val]) ans.emplace_back(root);
        else
        {
            if (root->left) ans.emplace_back(root->left);
            if (root->right) ans.emplace_back(root->right);
        }
        return ans;
    }
};