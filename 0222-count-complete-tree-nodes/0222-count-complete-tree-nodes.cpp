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
    int FindLeftHeight(TreeNode* root)
    {
        int h=0;
        while(root)
        {
            h++;
            root=root->left;
        }
        return h;
    }
    int FindRighttHeight(TreeNode* root)
    {
        int h=0;
        while(root)
        {
            h++;
            root=root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) 
    {
        if(!root) return 0;
        int l=FindLeftHeight(root);
        int r=FindRighttHeight(root);
        if(l==r) return (1<<l)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};