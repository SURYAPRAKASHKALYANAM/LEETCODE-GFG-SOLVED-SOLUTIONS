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
    void  preorder(TreeNode *p,vector<int>& v)
    {
        if(p==NULL)
        {
            v.emplace_back(NULL);
            return;
        }
        v.emplace_back(p->val);
        preorder(p->left,v);
        preorder(p->right,v);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        vector<int> pv,qv;
        preorder(p,pv);
        preorder(q,qv);
        return pv==qv;
    }
};