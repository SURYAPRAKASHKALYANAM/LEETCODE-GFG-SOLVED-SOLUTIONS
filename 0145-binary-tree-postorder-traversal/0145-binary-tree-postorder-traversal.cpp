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
    vector<int> sol;
    void in(TreeNode* root)
    {
        if(root==NULL)
            return;
        in(root->left);
        in(root->right);
        sol.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        in(root);
        return sol;
        
    }
};