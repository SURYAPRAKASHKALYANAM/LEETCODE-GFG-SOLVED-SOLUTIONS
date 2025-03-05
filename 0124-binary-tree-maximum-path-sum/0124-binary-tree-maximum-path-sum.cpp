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
    int helper(TreeNode* root, int& max_path_sum) {
        if (!root)
            return 0;
        int lh = max(0, helper(root->left, max_path_sum));
        int rh = max(0, helper(root->right, max_path_sum));
        max_path_sum = max(max_path_sum, root->val + lh + rh);
        return root->val + max(lh, rh);
    }
    int maxPathSum(TreeNode* root) {
        int max_path_sum = INT_MIN;
        helper(root, max_path_sum);
        return max_path_sum;
    }
};