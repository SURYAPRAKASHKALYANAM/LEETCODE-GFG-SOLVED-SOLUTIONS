/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool add(TreeNode *root, int target, int sum)
        {
            if (root == NULL || (root->left == NULL && root->right == NULL)) return sum == target;
            else if (root->left == NULL)
            {
                return add(root->right, target, sum + root->right->val);
            }
            else if (root->right == NULL)
            {
                return add(root->left, target, sum + root->left->val);
            }
            else return add(root->left, target, sum + (root->left->val)) || add(root->right, target, sum + root->right->val);
        }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root) return false;
        return add(root, targetSum,root->val);
    }
};