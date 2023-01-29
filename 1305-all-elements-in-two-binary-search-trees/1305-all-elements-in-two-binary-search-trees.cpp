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
    vector<int> s;
    void trav(TreeNode* root)
    {
        if(root==NULL) return;
        trav(root->left);
        s.emplace_back(root->val);
        trav(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    { 
        trav(root1);
        trav(root2);
        sort(s.begin(),s.end());
        return s;
    }
};