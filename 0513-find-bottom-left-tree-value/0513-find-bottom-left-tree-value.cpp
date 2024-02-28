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
        long val = LONG_MIN, depth = -1;
    void leftmost(TreeNode *root, int curr_depth)
    {
        if (!root) return;
        leftmost(root->left, curr_depth + 1);
        leftmost(root->right, curr_depth + 1);
        if (curr_depth == depth && val == LONG_MIN) val = root->val;
    }
    int maxdepth(TreeNode *root)
    {
        if (!root) return 0;
        int lh = maxdepth(root->left);
        int rh = maxdepth(root->right);
        return 1 + max(lh, rh);
    }
    int findBottomLeftValue(TreeNode *root)
    {
        depth = maxdepth(root);
        leftmost(root, 1);
        cout << depth;
        return val;
    }
};