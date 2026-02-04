/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxpathsum = INT_MIN;
    int helper(TreeNode* root) {
        if (!root)
            return 0;
        int lhsum = max(0, helper(root->left));
        int rhsum = max(0, helper(root->right));
        maxpathsum = max(maxpathsum, root->val + lhsum + rhsum);
        return root->val + max(lhsum, rhsum);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxpathsum;
    }
};