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
        int vall;
    void inorder(TreeNode *root, int depth)
    {
        if (!root) return;
        if (depth == 1 && root)
        {
            TreeNode *temp1 = new TreeNode(vall, root->left, NULL);
            TreeNode *temp2 = new TreeNode(vall, NULL, root->right);
            root->right = temp2;
            root->left = temp1;
            return;
        }
        inorder(root->left, depth - 1);
        inorder(root->right, depth - 1);
    }
    TreeNode* addOneRow(TreeNode *root, int val, int depth)
    {
        vall = val;
        if (depth == 1) return new TreeNode(val, root, NULL);
        inorder(root, depth - 1);
        return root;
    }
};