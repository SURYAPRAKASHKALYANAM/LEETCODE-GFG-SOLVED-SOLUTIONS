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
    int depth(TreeNode* root,int x,int h)
    {
        if(root==NULL) return 0;
        if(root->val==x) return h;
        int lh=depth(root->left,x,h+1);
        int rh=depth(root->right,x,h+1);
        return max(lh,rh);
    }
    void parent(TreeNode* root,int x,int* pa)
    {
        if(root==NULL) return ;
        if(root->left) if(root->left->val==x) *pa=root->val;
        if(root->right) if(root->right->val==x) *pa=root->val;
        parent(root->left,x,pa);
        parent(root->right,x,pa);
        
    }
    bool isCousins(TreeNode* root, int x, int y) 
    {
        int pax,pay;
        parent(root,x,&pax);
        parent(root,y,&pay);
        return depth(root,x,0)==depth(root,y,0) && pax!=pay;
    }
};
