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
    void inorder(vector<int>& in,TreeNode *root)
    {
        if(!root) return;
        inorder(in,root->left);
        in.emplace_back(root->val);
        inorder(in,root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(in,root);
        int low=0,high=in.size()-1;
        while(low<high)
        {
            int s=in[low]+in[high];
            if(s==k) return 1;
            if(s<k) low++;
            else high--;
        }
        return false;
    }
};