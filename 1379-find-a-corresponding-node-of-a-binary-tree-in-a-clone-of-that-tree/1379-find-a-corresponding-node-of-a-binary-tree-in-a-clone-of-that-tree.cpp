/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */

class Solution
{
    public:
        TreeNode* getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
        {
            TreeNode *r,*l;
            if (cloned == NULL) return NULL;
            l=getTargetCopy(original, cloned->left, target);
            if (l && target->val == l->val) return l;
            if (target->val == cloned->val) return cloned;
            r=getTargetCopy(original, cloned->right, target);
            if (r && target->val == r->val) return r;
            return cloned;
        }
};