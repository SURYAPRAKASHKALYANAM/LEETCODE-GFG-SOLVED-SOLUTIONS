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
class Solution {
public:
    int dia=-1;
    int maxdepth(TreeNode* root)
    {
        if(!root) return 0;
        int lh=maxdepth(root->left);
        int rh=maxdepth(root->right);
        dia=max(lh+rh,dia);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        maxdepth(root);
        return dia;
        
    }
};