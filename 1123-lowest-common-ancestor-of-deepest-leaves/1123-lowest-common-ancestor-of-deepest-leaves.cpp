/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class NodeValue
{
    public:
        TreeNode * node;
    int depth;
    NodeValue(TreeNode *node, int depth)
    {
        this->node = node;
        this->depth = depth;
    }
};
class Solution {
public:
    NodeValue depth(TreeNode *root)
    {
        if (!root) return NodeValue(NULL, 0);
        auto left = depth(root->left);
        auto right = depth(root->right);
        if (left.depth == right.depth) return NodeValue(root, 1 + left.depth);
        if (left.depth > right.depth) return NodeValue(left.node, 1 + left.depth);
        return NodeValue(right.node, 1 + right.depth);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return depth(root).node;
    }
};