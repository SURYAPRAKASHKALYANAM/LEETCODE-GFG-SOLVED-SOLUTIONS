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
        TreeNode* bstToGst(TreeNode *root)
        {
            int sum = 0;
            TreeNode *curr = root;
            while (curr)
            {
                if (curr->right == NULL)
                {
                    curr->val += sum;
                    sum = curr->val;
                    curr = curr->left;
                }
                else
                {
                    TreeNode *prev = curr->right;
                    while (prev->left && prev->left != curr) prev = prev->left;
                    if (prev->left == NULL)
                    {
                        prev->left = curr;
                        curr = curr->right;
                    }
                    else
                    {
                        curr->val += sum;
                        sum = curr->val;
                        prev->left = NULL;
                        curr = curr->left;
                    }
                }
            }
            return root;
        }
};