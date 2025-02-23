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
    // Referred solution --- need to revise
    int pre = 0, pos = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[pre]);
        pre++;
        if (root->val != postorder[pos])
            root->left = constructFromPrePost(preorder, postorder);
        if (root->val != postorder[pos])
            root->right = constructFromPrePost(preorder, postorder);
        pos++;
        return root;
    }
};