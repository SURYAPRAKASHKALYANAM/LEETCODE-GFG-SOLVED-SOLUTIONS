/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */

class Solution
{
    public:
        bool have(TreeNode *node, TreeNode *p)
        {
            if (!node) return false;
            if (node->val == p->val) return true;
            if (node->val > p->val) return have(node->left, p);
            else if (node->val < p->val) return have(node->right, p);
            return have(node->left, p) || have(node->right, p);
        }
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL) return NULL;
        TreeNode *ancl = lowestCommonAncestor(root->left, p, q);
        if (ancl) return ancl;
        ancl = lowestCommonAncestor(root->right, p, q);
        if (ancl) return ancl;
        if (have(root, p) && have(root, q)) return root;
        return NULL;
    }
};