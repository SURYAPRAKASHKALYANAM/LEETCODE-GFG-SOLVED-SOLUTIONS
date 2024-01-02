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
        TreeNode* rightmost(TreeNode *root)
        {
            if (root->right == NULL) return root;
            return rightmost(root->right);
        }
    TreeNode* attach(TreeNode *root)
    {
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;
        TreeNode *rightchild = root->right;
        TreeNode *lastright = rightmost(root->left);
        lastright->right = rightchild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode *root, int key)
    {
        if (!root) return root;
        if (root->val == key)
        {
            return attach(root);
        }
        TreeNode *temp = root;
        while (temp)
        {
            if (key < temp->val)
            {
                if (temp->left && temp->left->val == key)
                {
                    temp->left = attach(temp->left);
                    break;
                }
                else
                {
                    temp = temp = temp->left;
                }
            }
            else
            {
                if (temp->right && temp->right->val == key)
                {
                    temp->right = attach(temp->right);
                    break;
                }
                else
                {
                    temp = temp = temp->right;
                }
            }
        }
        return root;
    }
};