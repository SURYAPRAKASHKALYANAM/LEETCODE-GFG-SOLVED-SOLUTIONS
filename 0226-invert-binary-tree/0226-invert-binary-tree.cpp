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
    TreeNode* helper(TreeNode* root1, TreeNode* root) {
        if (!root)
            return NULL;
        if (root->right)
            root1->left = helper(new TreeNode(root->right->val), root->right);
        if (root->left)
            root1->right = helper(new TreeNode(root->left->val), root->left);
        return root1;
    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        return helper(new TreeNode(root->val), root);
    }
};