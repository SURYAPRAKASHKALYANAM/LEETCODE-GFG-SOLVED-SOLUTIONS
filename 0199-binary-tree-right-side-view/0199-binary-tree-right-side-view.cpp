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
    void find(TreeNode* root,int level,vector<int>& ans)
    {
       if(!root) return;
        if(ans.size()==level) ans.emplace_back(root->val);
        if(root->right) find(root->right,level+1,ans);
        if(root->left) find(root->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        find(root,0,ans);
        return ans;
        
    }
};