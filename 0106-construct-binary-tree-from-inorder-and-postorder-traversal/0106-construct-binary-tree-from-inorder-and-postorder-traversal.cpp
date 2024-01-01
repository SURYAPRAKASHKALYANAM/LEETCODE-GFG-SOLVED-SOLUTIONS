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
        TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
        {
            unordered_map<int, int> position;
            for (int i = 0; i < inorder.size(); i++) position[inorder[i]] = i;
            TreeNode *root = buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, position);
            return root;
        }
    TreeNode* buildTree(vector<int> &postorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, unordered_map< int, int> &position)
    {
        if ((prestart > preend) || (instart > inend)) return NULL;
        TreeNode *root = new TreeNode(postorder[preend]);
        int pos = position[root->val];
        int remleft = pos - instart;

        root->left = buildTree(postorder, prestart, prestart + remleft - 1, inorder, instart, pos - 1, position);
        root->right = buildTree(postorder, prestart + remleft, preend - 1, inorder, pos + 1, inend, position);
        return root;
    }
};