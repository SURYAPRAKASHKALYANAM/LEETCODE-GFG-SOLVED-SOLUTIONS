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
     int maxi=INT_MIN;
    int maxii(TreeNode* root)
    {
        if(root==NULL) return 0;
        int lh=max(0,maxii(root->left));
        int rh=max(0,maxii(root->right));
        maxi=max(maxi,(root->val)+lh+rh);
        return (root->val)+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) 
    {
       int s=maxii(root);
       return maxi;
    }
};