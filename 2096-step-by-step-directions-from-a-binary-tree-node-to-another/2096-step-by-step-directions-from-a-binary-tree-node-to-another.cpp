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
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root) return NULL;
        TreeNode *ancl = lowestCommonAncestor(root->left, p, q);
        if (ancl) return ancl;
        ancl = lowestCommonAncestor(root->right, p, q);
        if (ancl) return ancl;
        if (find(root, p->val) && find(root, q->val)) return root;
        return NULL;
    }
    TreeNode* find(TreeNode *root,int target)
    {
        if(!root) return NULL;
        if(root->val==target) return root;
        TreeNode* anc=find(root->left,target);
        if(anc) return anc;
        anc=find(root->right,target);
        return anc;
    }
    bool samebranch(TreeNode *node, TreeNode *p,int flag,string &s)
    {
        if(!flag)
        {
            if(!node) return false;
            if(node->val==p->val) return true;
            s+="L";
            bool l=samebranch(node->left,p,0,s);
            if(l) return true;
            s.pop_back();
            s+="R";
            bool r=samebranch(node->right,p,0,s);
            if(r) return true;
            s.pop_back();
        }
        if(!node) return false;
        if(node->val==p->val) return true;
        s+="U";
        bool l=samebranch(node->left,p,1,s);
        if(l) return true;
        s.pop_back();
        s+="U";
        bool r=samebranch(node->right,p,1,s);
        if(r) return true;
        s.pop_back();
        return l||r;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        string ans="";
        TreeNode* start=find(root,startValue);
        TreeNode* dest=find(root,destValue);
        if(samebranch(start,dest,0,ans))    return ans;
        else if(samebranch(dest,start,1,ans)) return ans;
        else
        {
            TreeNode* anc=lowestCommonAncestor(root,start,dest);
            samebranch(anc,start,1,ans);
            samebranch(anc,dest,0,ans);
            
        }
        return ans;
    }
};  