/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<TreeNode*> sorted;
    TreeNode* balanceBST(TreeNode *root)
    {
        inorder(root);
        return merge(0, sorted.size() - 1);
    }
    void inorder(TreeNode *root)
    {
        if (!root) return;
        inorder(root->left);
        sorted.emplace_back(root);
        inorder(root->right);
    }
    TreeNode* merge(int start, int end)
    {
        if (start > end) return NULL;
        int mid = (start + end) / 2;	// start + (end-start)/2;
        TreeNode *root = sorted[mid];
        root->left = merge(start, mid - 1);
        root->right = merge(mid + 1, end);
        return root;
    }
};